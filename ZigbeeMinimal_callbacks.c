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
#define ONE_SEC_DELAY_MS        (1000)
#define SHORT_DELAY_MS          (200)
#define SIX_SEC_DELAY_QS        (240)
#define RETRY_DELAY_QS          (40)
#define FETCH_RETRY_QS          (360) //(60)
#define BUTTON0                 (0)
#define BUTTON1                 (1)

// flag bits
#define COMMISSIONED            (0x01)
#define APS_QUEUED              (0x02)
#define BACKING_OFF             (0x04)

static sl_zigbee_event_t action_event;
static sl_zigbee_event_t commissioning_event;
static sl_zigbee_event_t init_ke_event;
static sl_zigbee_event_t find_services_event;
#define actionEvent (&action_event)
#define commissioningEvent (&commissioning_event)
#define initKeEvent (&init_ke_event)
#define findSvcsEvent (&find_services_event)
static sl_zigbee_event_t metro_event;
#define metroEvent (&metro_event)

static SxpState_t r_state = UNINITIALISED;
static uint8_t flags = 0;
static uint16_t sec;
//static utc_t han_loss;

static struct {
    struct cluster *cluster, *fetcher;
    uint8_t seq, cmd;
} req;

static void find_result(const EmberAfServiceDiscoveryResult *r);
static void fetch_run(void);
static void fetch_timeout(struct cluster *c);
static void not_authorised(struct cluster *c);

static void schedule_action(char *logstr, uint32_t state)
{
    emberAfCorePrintln(logstr);
    r_state = state;
    slxu_zigbee_event_set_active(actionEvent);
}

static void retry_wait(char *logstr, uint32_t state)
{
    emberAfCorePrintln(logstr, state);
    slxu_zigbee_event_set_delay_qs(actionEvent, RETRY_DELAY_QS);
}

void commissioningEventHandler(SLXU_UC_EVENT)
{
    EmberStatus status;
    EmberNetworkStatus n_stat;

    slxu_zigbee_event_set_inactive(commissioningEvent);
    
    n_stat = emberAfNetworkState();
    emberAfCorePrintln("------- commissioningEvent nwk status: 0x%X", n_stat);
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
    emberAfCorePrintln("------- KE_notification status: 0x%X  partnerID: 0x%X  delay 0x%X s",
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
        emberAfCorePrintln("------- Adding %s endpoint: addr: 0x%2X  clustId:0x%2X", 
                                    label, r->matchAddress, cluster_id);
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
    
    if (success)
        schedule_action("------- PLKE succeeded, entering IDLE", IDLE);
    else
        retry_wait("------- PLKE failed, r_state = 0x%X", r_state);
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
     case STARTING:
        // auto-restart - disabled in early dev
        //slxu_zigbee_event_set_delay_ms(commissioningEvent, COMMISSIONING_DELAY_MS);
        break;
        // successful join advances state to SCANNING in commissioningEventHandler
        // result picked up in emberAfStackStatusCallback, success advances to START_KE
        
     case START_KE:
        slxu_zigbee_event_set_delay_ms(initKeEvent, ONE_SEC_DELAY_MS);
        break;
        
     case FIND_METERS:
        slxu_zigbee_event_set_delay_ms(findSvcsEvent, SHORT_DELAY_MS);
        emberAfCorePrintln("-------  actionEvent in FIND_METERS: local NodeId = %2X", emberAfGetNodeId());
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
                retry_wait("------- GET_SDRs: %d", stat);
        } else
            schedule_action("------- State GET_SDRS: moving to GET_IEEE", GET_IEEE);
        break;

     case GET_IEEE:
        if ((nd = node_find_unknown()))
        {
#ifdef IM_LIST_DEBUG
            show_nodes("unknown found");
#endif
            if (EMBER_SUCCESS != (stat = emberAfFindIeeeAddress(nd->addr, got_ieee)))
                retry_wait("------- GET_IEEE: %d", stat);
        } else
            schedule_action("------- State GET_IEEE: moving to DO_PLKE", DO_PLKE);
        break;

     case DO_PLKE:
        if ((cl = cluster_find_unplked()))
        {
            emberAfCorePrintln("------- Found unPLKd KE cluster   c=%2X", cl); 
            if ((stat = emberAfInitiatePartnerLinkKeyExchange(cl->ep->node->addr, cl->ep->num, did_plke)))
                retry_wait("------- DO_PLKE: %d", stat);
            else
                cl->ep->node->plke++;
        } else {
            sec = 0;
            if (cl && cl->ep && cl->ep->node) 
                emberAfCorePrintln("-------   bailing - plke = %d", cl->ep->node->plke); 
            schedule_action("------- DO_PLKE - going to IDLE", IDLE);
        }
        break;
        
     case IDLE:
        if (sec >= 60 * 180)
            schedule_action("------- Returning to FIND_METERS", FIND_METERS);
        else if (EMBER_JOINED_NETWORK == emberAfNetworkState())
            fetch_run();
        break;

     default:
        emberAfCorePrintln("------- Unexpected actionEvent r_state = 0x%X", r_state); 
        if (r_state > IDLE) { // send failed / no response within 6s
            r_state = IDLE;
            fetch_timeout(req.fetcher);
        }
    }
}

static void fetch_run(void)
{
    cluster_do_rewind();

    struct cluster *anchor = cluster_next_circular(req.fetcher), *c;
    emberAfCorePrintln("\n\n-------  fetch_run first next_circular = %2X", anchor);
    utc_t now = utc_now();
    if ((c = anchor)) do {
        struct endpoint *e = c->ep;
//        if (e->node->unJoined >= 2); // ESME, don't probe
//        else if (now >= e->stall) // skip if stalled endpoint
        emberAfCorePrintln("-------  fetch_run next cluster = %2X  e->stall = %d", c, e->stall);
        if (now >= e->stall) // skip if stalled endpoint
            fetch_run_steps(c);
    } while (IDLE == r_state && (c = cluster_next_circular(c)) != anchor);
    req.fetcher = c;

    if (IDLE == r_state)
        slxu_zigbee_event_set_delay_qs(actionEvent, FETCH_RETRY_QS); // try again in 15 seconds
    else
        emberAfCorePrintln("------- fetch_run quit at cl = %2X  r_state = %d\n", c, r_state);
}

static void return_to_idle(void)
{
    if ((STOPPING != r_state) && (REBOOT != r_state)) {
        r_state = IDLE;     // clear old request
        slxu_zigbee_event_set_active(actionEvent);
    }
}

static void fetch_next(void)
{
    struct cluster *c = req.fetcher;
    if (c) {
        c->fetch++;
        c->retry = 0;
        c->ep->backoff = 0;
    }
    return_to_idle();
}

void fetch_cancel(struct cluster *c)
{
    if (req.fetcher == c)
        req.fetcher = 0;
}

void fetch_resume(void)
{
//    if (!req.fetcher) todo this is wrong, should move unbackoff here?
    if (r_state == IDLE)
        return_to_idle();
}

static void fetch_timeout(struct cluster *c)
{
	if (c && c->ep->node->unJoined)
		not_authorised(c);
	else if (c && ++c->retry == 5)
		fetch_next(); // still some shitty meters that just ignore commands forever
	else
		return_to_idle();
}

void metroRun(void)
{
    utc_t now = time_run(metroEvent), ok = time_ok();

    if (r_state >= IDLE)
    {
        sec++;
        emberAfCorePrint("%d ",sec);
    }

    if (ok && sec % 10 == 0) {
        tree_rewind(0, REWIND_TENSECS);
        if (sec % 60 == 0) {
            tree_rewind(0, REWIND_MINUTE);
            if (sec % 1800 == 0)
                tree_rewind(0, REWIND_HALFHOUR);
//            if (han_loss)
//                time_lost_han((now - han_loss) / 60);
    emberAfCorePrintln("meter_metro call");
//            meter_metronome(now);
        }
        fetch_resume();
    }
//    if (ok)
//    emberAfCorePrintln("meter_metro call");
//        meter_metronome(now);
}

void attr_get(struct cluster *c, int num, ...)
{
    uint16_t buf[16], got = 0;
    va_list l;
    va_start(l, num);
    while (got < num)
        buf[got++] = va_arg(l, int);
    va_end(l);

emberAfCorePrintln("----  attr_get: cl=%2X  cl_id=%2X  num=%d", c, c->id, num);
    emberAfFillCommandGlobalClientToServerReadAttributes(c->id, buf, got * 2);
    send_common(c, DO_ATTR);
}

uint8_t finish_send(struct cluster *c, char type, EmberStatus stat, uint8_t seq)
{
    if (stat == EMBER_NETWORK_DOWN); // don't do shit, stay idle until back on HAN
    else if (stat)
        retry_wait("send status = %02X", stat);
    else {
        req.cluster = c;
        r_state = type;
        flags |= APS_QUEUED;
        slxu_zigbee_event_set_delay_qs(actionEvent, SIX_SEC_DELAY_QS);
    }
    return req.seq = seq;
}

static void not_authorised(struct cluster *c)
{
    // back off for 1 2 4 8 16 32 32 32 32 32 32 32 32 32 = 319 minutes total, 14 distinct periods
    struct endpoint *e = c->ep;
    if (e->backoff < 14) {
        uint8_t i = e->backoff < 5 ? e->backoff : 5;
        uint32_t w = 60 << i;
        if (time_ok())
            e->backoff++;
        e->stall = utc_now() + w;
    } else
        e->stall = 0xFFFFFFFF;
    emberAfCorePrintln("------  Stalling %2X:%X till %d\n", e->node->addr, e->num, e->stall);
    slxu_zigbee_event_set_active(actionEvent);
}

void emberAfMainInitCallback(void)
{
    slxu_zigbee_event_init(actionEvent, actionRun);
    slxu_zigbee_event_init(commissioningEvent, commissioningEventHandler);
    slxu_zigbee_event_init(initKeEvent, initKeEventHandler);
    slxu_zigbee_event_init(findSvcsEvent, findServicesHandler);
    slxu_zigbee_event_init(metroEvent, metroRun);
}

void emberAfMainTickCallback(void)
{
    if (UNINITIALISED == r_state) {
        r_state = STARTING;
        slxu_zigbee_event_set_active(actionEvent);
//        slxu_zigbee_event_set_active(metroEvent);
    }
    else if (STOPPING == r_state) {
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

    if (EMBER_NETWORK_UP == status || EMBER_TRUST_CENTER_EUI_HAS_CHANGED == status)
    {
        //EmberNetworkParameters np;
        //if (EMBER_NETWORK_UP == status && EMBER_SUCCESS == emberGetNetworkParameters(&np)) {
        //uint8_t emberAfGetRadioChannel(void);
        //    emberAfCorePrintln("Joined %4x/%a at %idBm on %i\n", np.panId, np.extendedPanId, np.radioTxPower, np.radioChannel);
        //    prepare_ack_ddr(np.radioChannel >= 128);
        //}
        flags &= ~BACKING_OFF;
/*
		if (han_loss) {
			if (utc_now() >= han_loss + 30)
				tree_rewind(0, REWIND_RESTART);
			han_loss = 0;
		}
*/
		if (status == EMBER_TRUST_CENTER_EUI_HAS_CHANGED || no_tc_link_key())
            r_state = START_KE;

        slxu_zigbee_event_set_active(actionEvent);
    } 
    else 
    {  /* neither  network up  nor  EUI changed */
        if (flags & COMMISSIONED && emberAfNetworkState() == EMBER_NO_NETWORK) {
            flags &= ~COMMISSIONED;
            emberAfCorePrintln("------  StackStatusCb  doing loss-of-network reboot");            
            r_state = STOPPING;
        }
/*
		if (han_loss == 0) {
			han_loss = utc_now();
			time_lost_han(0);
		}
*/
    }
}

bool emberAfReadAttributesResponseCallback(EmberAfClusterId clusterId, uint8_t *buffer, uint16_t bufLen)
{
    EmberAfClusterCommand *af = emberAfCurrentCommand();
    emberAfCorePrintln("------  ReadAttr Response Cb  cl: %2X  ClCmd: %2X", clusterId, af?af->commandId:0);            
    //csafe("0a", af);

    struct cluster *c = clus_find_af(af);
    if (!c || !c->ops || !c->ops->attr)
        return false; // unknown cluster or no handler

    uint8_t *p = buffer, *end = p + bufLen;
    while (p < end) {
        struct zattr a;
        a.id = p[0] | p[1] << 8, p += 2;
        a.status = *p++;
        if (a.status == 0) {
            a.type = *p++;
            a.data = p;
            p += emberAfIsThisDataTypeAStringType(a.type) ? 1 + emberAfStringLength(p) : emberAfGetDataSize(a.type); // find length
        } else if (a.status == EMBER_ZCL_STATUS_NOT_AUTHORIZED && c->ep->node->unJoined) {
            not_authorised(c);
            return true;
        }
        emberAfCorePrintln("------  ReadAttr running attr(%2X) for cl %2X -  zattr.id: %2X  zattr.type: %2X", c->ops->attr, c, a.id, a.type);
        show_meter("before attr", c->ep);
        c->ops->attr(c, &a); // dispatch
        show_meter("after attr", c->ep);
    }

    if (~af->buffer[0] & ZCL_DISABLE_DEFAULT_RESPONSE_MASK)
        emberAfSendDefaultResponse(af, EMBER_ZCL_STATUS_SUCCESS);

    if (DO_ATTR == r_state && req.cluster == c && req.seq == af->seqNum)
        fetch_next();

    return true;
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
    else if (SL_SIMPLE_BUTTON_INSTANCE(BUTTON1) == handle) {
        if (SL_SIMPLE_BUTTON_RELEASED == sl_button_get_state(handle)) {
            if ((IDLE == r_state) && (EMBER_JOINED_NETWORK == emberAfNetworkState()))
                fetch_run();
        }
    }
}
#endif
