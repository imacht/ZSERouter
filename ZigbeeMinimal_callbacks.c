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

#define ROUTER_ENDPOINT (1)
#define COORD_ENDPOINT  (1)

#define ALL_CHANNELS_MASK       (0x07FFF800)
#define COMMISSIONING_DELAY_MS  (5000)
#define INIT_KE_DELAY_MS        (1000)
#define BUTTON0                 (0)
#define BUTTON1                 (1)

// flag bits
#define COMMISSIONED	(1)


static sl_zigbee_event_t commissioning_event;
static sl_zigbee_event_t init_ke_event;
static sl_zigbee_event_t find_services_event;
#define commissioningEvent (&commissioning_event)
#define initKeEvent (&init_ke_event)
#define findSvcsEvent (&find_services_event)

static struct cluster *aclust;

typedef enum {
    UNINITIALISED,
    STOPPING,
    REBOOT,
    SCANNING,
    START_KE,
    FIND_METERS,
    FIND_PRICES,
//TODO:    FIND_OTA,
} JoinStage_t;
static JoinStage_t r_state = UNINITIALISED;
static uint8_t flags = 0;

static void find_result(const EmberAfServiceDiscoveryResult *r);

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
    slxu_zigbee_event_set_inactive(initKeEvent);
    emberAfCorePrintln("------- KE_notification status: 0x%X  partnerID: 0x%X  delay 0x%Xs",
                       status, partnerShortId, delayInSeconds);
    if (LINK_KEY_ESTABLISHED == status)
    {
        emberAfCorePrintln("------- LINK_KEY_ESTABLISHED ------");
        flags |= COMMISSIONED;
        r_state = FIND_METERS;
        slxu_zigbee_event_set_delay_ms(findSvcsEvent, 100);
    }
    return true;
}

void findServicesHandler()
{
    EmberStatus stat;
    uint16_t clust_id = 0;

    slxu_zigbee_event_set_inactive(findSvcsEvent);
    switch (r_state) {
     case FIND_METERS:
         clust_id = ZCL_SIMPLE_METERING_CLUSTER_ID; break;
     case FIND_PRICES:
         clust_id = ZCL_PRICE_CLUSTER_ID; break;
     default: ;
    }
    stat = emberAfFindDevicesByProfileAndCluster(
                                    EMBER_RX_ON_WHEN_IDLE_BROADCAST_ADDRESS,
                                    SE_PROFILE_ID,
                                    clust_id,
                                    EMBER_AF_SERVER_CLUSTER_DISCOVERY,
                                    find_result);
}

void dbgprnt_clst(struct endpoint* endp) {
    emberAfCorePrintln("-------  ep next: 0x%02X   ep node: 0x%02X   ep meter: 0x%02X",
                       endp->next?endp->next:0, endp->node?endp->node:0, endp->meter?endp->meter:0);
}

static void find_result(const EmberAfServiceDiscoveryResult *r)
{
    char label[20];
    uint16_t cluster_id;

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
            break;
        case EMBER_AF_BROADCAST_SERVICE_DISCOVERY_RESPONSE_RECEIVED  :
            emberAfCorePrintln("------- %s Find result status = EMBER_AF_BROADCAST_SERVICE_DISCOVERY_RESPONSE_RECEIVED", label);
            break;
        case EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE_WITH_RESPONSE  :
            emberAfCorePrintln("------- %s Find result status = EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE_WITH_RESPONSE", label);
            break;
        case EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE_WITH_EMPTY_RESPONSE :
            emberAfCorePrintln("------- %s Find result status = EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE_WITH_EMPTY_RESPONSE", label);
            break;
        default:
            emberAfCorePrintln("------- UNICAST or unknown result status");
            return;
    }
    if (emberAfHaveDiscoveryResponseStatus(r->status)) {
        const EmberAfEndpointList* l = r->responseData;
        struct cluster* nc;
        
        emberAfCorePrintln("------- %s Find result: addr: 0x%02X  count: %d",
                                   label, r->matchAddress, l->count);
        emberAfCorePrintln("------- Adding %s endpoint: addr: 0x%02X  clustId:0x%02X", label, r->matchAddress, cluster_id);
        endpoint_add_new(r->matchAddress, l->list, l->count, cluster_id);

        nc = cluster_next_circular(aclust);
        if (nc) aclust = nc;
        int i = 1;
        emberAfCorePrintln("------- %s Find cluster: addr: 0x%02X", label, nc);
        while (nc) {
            emberAfCorePrintln("-------  cluster#%d  id: 0x%02X   ep: 0x%02X   ops: 0x%02X   next: 0x%02X", 
                                         i++, nc->id, nc->ep, nc->ops?nc->ops:0, nc->next?nc->next:0);
            if (nc->ep) dbgprnt_clst(nc->ep);
            nc = nc->next;
        }

        nc = cluster_next_circular(nc);
        if (nc != aclust) {
            i = 1;
            emberAfCorePrintln("------- %s next circ cluster: addr: 0x%02X", label, nc);
            while (nc) {
                emberAfCorePrintln("-------  cluster#%d  id: 0x%02X   ep: 0x%02X   ops: 0x%02X   next: 0x%02X", 
                                             i++, nc->id, nc->ep, nc->ops?nc->ops:0, nc->next?nc->next:0);
                if (nc->ep) dbgprnt_clst(nc->ep);
                nc = nc->next;
            }
        }
        i = 0;
        while (i < l->count)
            emberAfCorePrintln("-------             ep list entry: 0x%X", (uint8_t *)l->list[i++]);
    }
    if (EMBER_AF_BROADCAST_SERVICE_DISCOVERY_RESPONSE_RECEIVED != r->status) {
        // Discovery complete
        if (FIND_METERS == r_state)
        {
            r_state +=1;
            slxu_zigbee_event_set_delay_ms(findSvcsEvent, 100);
        }
    }
}

void emberAfMainInitCallback(void)
{
    slxu_zigbee_event_init(commissioningEvent, commissioningEventHandler);
    slxu_zigbee_event_init(initKeEvent, initKeEventHandler);
    slxu_zigbee_event_init(findSvcsEvent, findServicesHandler);
    
    slxu_zigbee_event_set_delay_ms(commissioningEvent, COMMISSIONING_DELAY_MS);
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
        
	emberAfCorePrintln("------  StackStatus = 0x%02X,  NetworkState = %d\n", status, emberAfNetworkState());

	if (EMBER_NETWORK_UP != status && EMBER_TRUST_CENTER_EUI_HAS_CHANGED != status)
		if (flags & COMMISSIONED && emberAfNetworkState() == EMBER_NO_NETWORK) {
            flags &= ~COMMISSIONED;
            emberAfCorePrintln("------  StackStatusCb  doing loss-of-network reboot");            
			r_state = STOPPING;
        }
    
    if (EMBER_NETWORK_UP == status && SCANNING == r_state) {
        r_state = START_KE;
        slxu_zigbee_event_set_active(initKeEvent);
    }
}

void emberAfPluginNetworkFindFinishedCallback(EmberStatus status)
{
	emberAfCorePrintln("------- PluginNetworkFindFinishedCallback status : 0x%02X", status);
	if (EMBER_NO_BEACONS == status && SCANNING == r_state) {
		// set BACKING_OFF - 
	}
}

bool emberAfPluginNetworkFindJoinCallback(EmberZigbeeNetwork *n, uint8_t lqi, int8_t rssi)
{
	emberAfCorePrintln("------- PluginNetworkFindFinishedCallback nwk found chan: %d  panId: 0x%02X  lqi:%d  rssi: %d\n", 
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
