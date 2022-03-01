/*******************************************************************************
 * @file
 * @brief Initiated from ZigbeeMinimal sample application.
 *******************************************************************************
 *
 ******************************************************************************/

#include "app/framework/include/af.h"
#include "network-find.h"
#include "ember-types.h"
//#include "update-tc-link-key.h"
#include "zmeter/zmeter.h"
#include "gubbins.h"

/* define for node/endpoint/cluster list debug prints */
//#define IM_LIST_DEBUG

#define ROUTER_ENDPOINT (1)
#define COORD_ENDPOINT  (1)

#define ALL_CHANNELS_MASK       (0x07FFF800)
#define COMMISSIONING_DELAY_MS  (5000)
#define REPEAT_DELAY_MS         (3000)
#define INIT_KE_DELAY_MS        (1000)
#define SHORT_DELAY_MS          (200)
#define RETRY_DELAY_QS          (40)
#define BUTTON0                 (0)
#define BUTTON1                 (1)

// flag bits
#define COMMISSIONED    (1)

static sl_zigbee_event_t action_event;
static sl_zigbee_event_t commissioning_event;
static sl_zigbee_event_t init_ke_event;
static sl_zigbee_event_t find_services_event;
#define actionEvent (&action_event)
#define commissioningEvent (&commissioning_event)
#define initKeEvent (&init_ke_event)
#define findSvcsEvent (&find_services_event)

typedef enum {
    UNINITIALISED,
    STOPPING,
    REBOOT,
    SCANNING,
    START_KE,
    FIND_METERS,
    FIND_PRICES,
    GET_SDRS,
    GET_IEEE,
    DO_PLKE,
//TODO:    FIND_OTA,
    IDLE
} SxpState_t;

static SxpState_t r_state = UNINITIALISED;
static uint8_t flags = 0;
static uint16_t sec;

static void find_result(const EmberAfServiceDiscoveryResult *r);


static void short_wait(char *logstr, uint32_t state)   // need to increase delay - nom. 10s
{
    emberAfCorePrintln(logstr, state);
    slxu_zigbee_event_set_delay_ms(actionEvent, SHORT_DELAY_MS);
}

void commissioningEventHandler(SLXU_UC_EVENT)
{
    EmberStatus status;
    EmberNetworkStatus n_stat;

    slxu_zigbee_event_set_inactive(commissioningEvent);
    
    n_stat = emberAfNetworkState();
    emberAfCorePrintln("------- commissioningEvent nwk status: 0x%02X", n_stat);
    if (EMBER_NO_NETWORK != n_stat)
        return;
    
    r_state = SCANNING;
    // allow joining on all possible channels
    // TODO: might be quicker to search preferred first, investigate?
    status = emberAfSetFormAndJoinChannelMask(0, ALL_CHANNELS_MASK);
    emberAfCorePrintln("------- SetFormAndJoinChannelMask returned : 0x%X", status);
    EmberNetworkInitStruct init_struct = { EMBER_NETWORK_INIT_PARENT_INFO_IN_TOKEN };
       status = emberNetworkInit(&init_struct);
    
    if (EMBER_NOT_JOINED == status) {
        emberAfCorePrintln("------- NetworkInit returned EMBER_NOT_JOINED, searching for network...");
        status = emberAfStartSearchForJoinableNetwork();
        emberAfCorePrintln("------- StartSearchForJoinableNetwork returned : 0x%X", status);
    }
    else if (status)        
        emberAfCorePrintln("------- NetworkInit returned  0x%X", status);
    else 
        emberAfCorePrintln("------- NetworkInit returned Success");
}

void initKeEventHandler(SLXU_UC_EVENT)
{
    EmberStatus status;

    slxu_zigbee_event_set_inactive(initKeEvent);

    status = emberAfInitiateKeyEstablishment(0x0000, COORD_ENDPOINT);
    emberAfCorePrintln("------- InitiateKeyEstablishment returned : 0x%X", status);
}

boolean emberAfPluginKeyEstablishmentEventCallback(EmberAfKeyEstablishmentNotifyMessage status,
                                        boolean amInitiator,
                                        EmberNodeId partnerShortId,
                                        int8u delayInSeconds)
{
    emberAfCorePrintln("------- KE_notification status: 0x%X  partnerID: 0x%X  delay 0x%Xs",
                       status, partnerShortId, delayInSeconds);
    if (LINK_KEY_ESTABLISHED == status)
    {
        emberAfCorePrintln("------- LINK_KEY_ESTABLISHED ------");
        flags |= COMMISSIONED;
        r_state = FIND_METERS;
        slxu_zigbee_event_set_active(actionEvent);
    }
    return true;
}

void findServicesHandler(void)
{
    EmberStatus stat;
    uint16_t clust_id = 0;
    
    slxu_zigbee_event_set_inactive(findSvcsEvent);
    switch (r_state) {
     case FIND_METERS:
         clust_id = ZCL_SIMPLE_METERING_CLUSTER_ID; break;
     case FIND_PRICES:
         clust_id = ZCL_PRICE_CLUSTER_ID; break;
     default: 
        emberAfCorePrintln("-------  UNEXPECTED findServices event: r_state = %d", r_state);
        return;
    }
    stat = emberAfFindDevicesByProfileAndCluster(
                                    EMBER_RX_ON_WHEN_IDLE_BROADCAST_ADDRESS,
                                    SE_PROFILE_ID,
                                    clust_id,
                                    EMBER_AF_SERVER_CLUSTER_DISCOVERY,
                                    find_result);
}

static void find_result(const EmberAfServiceDiscoveryResult *r)
{
    char label[20];
    uint16_t cluster_id = 0;
    boolean discoveryComplete = false;

    if (r->zdoRequestClusterId != MATCH_DESCRIPTORS_REQUEST || r->matchAddress == emberAfGetNodeId())
        return;

    switch (r_state) {
     case FIND_METERS:  strcpy(label, "Meter"); cluster_id = ZCL_SIMPLE_METERING_CLUSTER_ID; break;
     case FIND_PRICES:  strcpy(label, "Price"); cluster_id = ZCL_PRICE_CLUSTER_ID; break;
     default: ;
    }
    switch (r->status) {
        case EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE:
            emberAfCorePrintln("------- %s Find result status = EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE\n", label);
            discoveryComplete = true;
            break;
        case EMBER_AF_BROADCAST_SERVICE_DISCOVERY_RESPONSE_RECEIVED  :
            emberAfCorePrintln("------- %s Find result status = EMBER_AF_BROADCAST_SERVICE_DISCOVERY_RESPONSE_RECEIVED", label);
            break;
        case EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE_WITH_RESPONSE  :
            emberAfCorePrintln("------- %s Find result status = EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE_WITH_RESPONSE", label);
            discoveryComplete = true;
            break;
        case EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE_WITH_EMPTY_RESPONSE :
            emberAfCorePrintln("------- %s Find result status = EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE_WITH_EMPTY_RESPONSE", label);
            discoveryComplete = true;
            break;
        default:
            emberAfCorePrintln("------- UNICAST or unknown result status");
            return;
    }
    if (emberAfHaveDiscoveryResponseStatus(r->status)) {
        const EmberAfEndpointList* l = r->responseData;
        
#ifdef IM_LIST_DEBUG
        show_endpoints("find_result before");
        show_clusters("find_result before");
#endif
        emberAfCorePrintln("------- %s Find result: addr: 0x%2X  count: %d",
                                   label, r->matchAddress, l->count);
        emberAfCorePrintln("------- Adding %s endpoint: addr: 0x%2X  clustId:0x%2X", label, r->matchAddress, cluster_id);
        endpoint_add_new(r->matchAddress, l->list, l->count, cluster_id);
#ifdef IM_LIST_DEBUG
        show_endpoints("find_result after");
        show_clusters("find_result after");
#endif
    }
    if (discoveryComplete) {
        r_state +=1;
        slxu_zigbee_event_set_active(actionEvent);
    }
}

static void got_sdr(const EmberAfServiceDiscoveryResult *r)
{
    if (r->zdoRequestClusterId != SIMPLE_DESCRIPTOR_REQUEST)
        return;

    if (emberAfHaveDiscoveryResponseStatus(r->status)) {
        EmberAfClusterList *l = (EmberAfClusterList*)r->responseData;
        struct endpoint *e = endp_find(r->matchAddress, l->endpoint);
        if (e) {
            e->profid = l->profileId;
            e->devid = l->deviceId;
            const uint16_t *p = l->inClusterList, *end = p + l->inClusterCount;
            emberAfCorePrintln("-------  Simple Descriptor Req  %2X / %X", e->node->addr, e->num);
            while (p < end) {
                emberAfCorePrintln("-------     %2X", *p);
                cluster_get(e, *p++);
            }
        }
#ifdef IM_LIST_DEBUG
        show_clusters("after got_sdr");
        show_endpoints("after got_sdr");
#endif
    }

    if (GET_SDRS == r_state)
        slxu_zigbee_event_set_active(actionEvent);
}

static void show_aps_key(struct node *n)
{
    uint8_t i;
    EmberKeyStruct k;
    if ((n->addr == EMBER_TRUST_CENTER_NODE_ID  &&  emberGetKey(EMBER_TRUST_CENTER_LINK_KEY, &k) == EMBER_SUCCESS) 
        || ((i = emberFindKeyTableEntry(n->ieee, true)) < 255  &&  emberGetKeyTableEntry(i, &k) == EMBER_SUCCESS))
    {
        uint8_t *m = k.key.contents, *n = k.partnerEUI64;
        emberAfCorePrintln("-------  APS key = %X %X %X %X %X %X %X %X  %X %X %X %X %X %X %X %X    Partner EUI64 = %X %X %X %X %X %X %X %X", 
                            m[0],m[1],m[2],m[3],m[4],m[5],m[6],m[7],m[8],m[9],m[10],m[11],m[12],m[13],m[14],m[15],
                            n[7],n[6],n[5],n[4],n[3],n[2],n[1],n[0]); // EUI64_SIZE=8
    }
}

static void got_ieee(const EmberAfServiceDiscoveryResult *r)
{
    struct node *n = node_find_by_nwk(r->matchAddress);
    if (n && r->status == EMBER_AF_UNICAST_SERVICE_DISCOVERY_COMPLETE_WITH_RESPONSE) {
        MEMMOVE(n->ieee, r->responseData, 8);
        emberAfCorePrintln("-------  IEEE addr rcvd = %X %X %X %X  %X %X %X %X",
                            n->ieee[0], n->ieee[1], n->ieee[2], n->ieee[3], n->ieee[4], n->ieee[5], n->ieee[6], n->ieee[7]);
        emberAfAddAddressTableEntry(n->ieee, n->addr);
        show_aps_key(n);
#ifdef IM_LIST_DEBUG
        show_nodes("after got_ieee");
#endif
    }

    if (GET_IEEE == r_state)
        slxu_zigbee_event_set_active(actionEvent);
}

static void did_plke(bool success)
{
    if (DO_PLKE != r_state) return;
    
    if (success) {
        r_state = IDLE;
        short_wait("------- PLKE succeeded, r_state = %d", r_state);
    } else
        short_wait("------- PLKE failed, r_state = %d", r_state);
}

void actionRun(void)
{
    struct endpoint *ep;
    struct node *nd;
    struct cluster *cl;
    EmberStatus stat;

    slxu_zigbee_event_set_inactive(actionEvent);
    
    switch(r_state) {
     case UNINITIALISED:
        slxu_zigbee_event_set_delay_ms(commissioningEvent, COMMISSIONING_DELAY_MS);
        break;
        // successful join advances state to SCANNING in commissioningEventHandler
        // result picked up in emberAfStackStatusCallback, success advances to START_KE
        
     case START_KE:
        slxu_zigbee_event_set_delay_ms(initKeEvent, INIT_KE_DELAY_MS);
        break;
        
     case FIND_METERS:
        slxu_zigbee_event_set_delay_ms(findSvcsEvent, SHORT_DELAY_MS);
        break;
        
     case FIND_PRICES:
        slxu_zigbee_event_set_delay_ms(findSvcsEvent, SHORT_DELAY_MS);
        break;
        
     case GET_SDRS:
        if ((ep = endpoint_find_undescribed()))
        {
#ifdef IM_LIST_DEBUG
            show_endpoints("found undescribed");
            show_clusters("found undescribed");
#endif
            if (EMBER_SUCCESS != (stat = emberAfFindClustersByDeviceAndEndpoint(ep->node->addr, ep->num, got_sdr)))
                short_wait("------- GET_SDRs: %d", stat);
        } else {
            r_state = GET_IEEE;
            short_wait("------- State GET_SDRS: moving to GET_IEEE = %2X", stat);
        }            
        break;

     case GET_IEEE:
        if ((nd = node_find_unknown()))
        {
#ifdef IM_LIST_DEBUG
            show_nodes("unknown found");
#endif
            if (EMBER_SUCCESS != (stat = emberAfFindIeeeAddress(nd->addr, got_ieee)))
                short_wait("------- GET_IEEE: %d", stat);
        } else {
            r_state = DO_PLKE;
            short_wait("------- State GET_IEEE: moving to DO_PLKE = %2X", stat);
        }
        break;

     case DO_PLKE:
#ifdef IM_LIST_DEBUG
        show_nodes("before find_unplked");
#endif
        if ((cl = cluster_find_unplked()))
        {
            emberAfCorePrintln("------- Found unPLKd KE cluster   c=%2X", cl); 
            if ((stat = emberAfInitiatePartnerLinkKeyExchange(cl->ep->node->addr, cl->ep->num, did_plke)))
                short_wait("------- DO_PLKE: %d", stat);
            else
                cl->ep->node->plke++;
        } else {
            sec = 0;
            r_state = IDLE;
            if (cl && cl->ep && cl->ep->node) 
                emberAfCorePrintln("-------   bailing - plke = %2X", cl->ep->node->plke); 
            short_wait("------- DO_PLKE - going to IDLE, cl = %2X", cl?cl:0);
        }
        break;
        
	 case IDLE:
		if (sec >= 60 * 180)
        {
			r_state = FIND_METERS;
            short_wait("------- Returning to FIND_METERS", r_state);
        }
		else if (EMBER_JOINED_NETWORK == emberAfNetworkState())
			/*fetch_run()*/ ;
        break;

     default:
        emberAfCorePrintln("------- Unexpected actionEvent r_state = %d", r_state); 
    }
}

void emberAfMainInitCallback(void)
{
    slxu_zigbee_event_init(actionEvent, actionRun);
    slxu_zigbee_event_init(commissioningEvent, commissioningEventHandler);
    slxu_zigbee_event_init(initKeEvent, initKeEventHandler);
    slxu_zigbee_event_init(findSvcsEvent, findServicesHandler);
}

void emberAfMainTickCallback(void)
{
    if (STOPPING == r_state) {
        if (!emberPendingAckedMessages() && emberOkToNap()) {
            emberStackPowerDown();
            r_state = REBOOT;
        }
    } else if (REBOOT == r_state) {
        //if (emberSerialWriteUsed(APP_SERIAL) == 0)
            halReboot();
    }
}

/** @brief Stack Status
 *
 * This function is called by the application framework from the stack status
 * handler. The framework will always process the stack status after the
 * callback returns.
 *
 * Respond to network going up with proceeding to KE
 *
 * @param status   Ver.: always
 */
void emberAfStackStatusCallback(EmberStatus status)
{
    if (UNINITIALISED == r_state)   // ignore early bollocks reports
        return;
        
    emberAfCorePrintln("------  StackStatus = 0x%X,  NetworkState = %d\n", status, emberAfNetworkState());

    if (EMBER_NETWORK_UP != status && EMBER_TRUST_CENTER_EUI_HAS_CHANGED != status)
        if (flags & COMMISSIONED && emberAfNetworkState() == EMBER_NO_NETWORK) {
            flags &= ~COMMISSIONED;
            emberAfCorePrintln("------  StackStatusCb  doing loss-of-network reboot");            
            r_state = STOPPING;
        }
    
    if (EMBER_NETWORK_UP == status && SCANNING == r_state) {
        r_state = START_KE;
        slxu_zigbee_event_set_active(actionEvent);
    }
}

void emberAfPluginNetworkFindFinishedCallback(EmberStatus status)
{
    emberAfCorePrintln("------- PluginNetworkFindFinishedCallback status : 0x%X", status);
    if (EMBER_NO_BEACONS == status && SCANNING == r_state) {
        // set BACKING_OFF - 
    }
}

bool emberAfPluginNetworkFindJoinCallback(EmberZigbeeNetwork *n, uint8_t lqi, int8_t rssi)
{
    emberAfCorePrintln("------- PluginNetworkFindFinishedCallback nwk found chan: %d  panId: 0x%X  lqi:%d  rssi: %d\n", 
                    n->channel, n->panId, lqi, rssi);
    return true;
}

/** @brief Hal Button Isr
 *
 * This callback is called by the framework whenever a button is pressed on the
 * device. This callback is called within ISR context.
 *
 * @param button The button which has changed state, either BUTTON0 or BUTTON1
 * as defined in the appropriate BOARD_HEADER.
 *
 * Use Button0 release to kick off trying to join network
 */
#if defined(SL_CATALOG_SIMPLE_BUTTON_PRESENT) && (EMBER_AF_PLUGIN_IDLE_SLEEP_USE_BUTTONS == 0)
#include "sl_simple_button.h"
#include "sl_simple_button_instances.h"
void sl_button_on_change(const sl_button_t *handle)
{
  if (SL_SIMPLE_BUTTON_INSTANCE(BUTTON0) == handle) {
    if (SL_SIMPLE_BUTTON_RELEASED == sl_button_get_state(handle)) {
      slxu_zigbee_event_set_active(commissioningEvent);
    }
  }
}
#endif
