/* Gubbins from hm.c /   for handling endpoint etc. lists & updating */

#include <zmeter.h>
#include <stdlib.h>
#include "gubbins.h"
#include "zap-id.h"

#include "app/framework/include/af.h"

/* define for node/endpoint/cluster list debug prints */
//#define IM_LIST_DEBUG

#ifdef IM_LIST_DEBUG
extern struct node *nodes;
extern struct endpoint *endpoints;
extern struct cluster *clusters;
#endif

extern frt fr_table[];

/* default defs to match externs in zmeter.h */
void* zalloc(size_t bytes) { return calloc(bytes,1); }
void dbgf(const char *fmt, ...) { }

// zmeter compatibility

uint8_t isnull(uint8_t *buf, uint8_t bytes)
{
    while (bytes && *buf++ == 0)
        bytes--;
    return 0 == bytes;
}

uint8_t ieee_from_nwk(uint16_t nwk, uint8_t *out) { return 0; }

static const uint16_t coi[] = 
        {   ZCL_BASIC_CLUSTER_ID, 
            ZCL_TIME_CLUSTER_ID, 
            //ZCL_OTA_BOOTLOAD_CLUSTER_ID, 
            ZCL_PRICE_CLUSTER_ID, 
            ZCL_SIMPLE_METERING_CLUSTER_ID, 
            ZCL_MESSAGING_CLUSTER_ID, 
            ZCL_PREPAYMENT_CLUSTER_ID, 
            ZCL_CALENDAR_CLUSTER_ID, 
            ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, 
            ZCL_KEY_ESTABLISHMENT_CLUSTER_ID, 
            //ZCL_TUNNELING_CLUSTER_ID
            };
            
uint8_t link_key_ok(uint8_t *ieee)
{
    EmberKeyStruct k;
  emberAfCorePrintln("------- l_k_ok start"); 
    uint8_t i = emberFindKeyTableEntry(ieee, true);
  emberAfCorePrintln("------- l_k_ok table entry i = %d", i); 
    return (i != 0xFF) && (EMBER_SUCCESS == emberGetKeyTableEntry(i, &k));
}

struct cluster* clus_find_af(EmberAfClusterCommand *af)
{
    struct endpoint *e = endp_find(af->source, af->apsFrame->sourceEndpoint);
    return e ? cluster_find(e, af->apsFrame->clusterId) : 0;
}

struct cluster* cluster_get(struct endpoint *e, uint16_t id)
{
    const uint16_t *p = coi, *end = p + sizeof(coi) / sizeof(coi[0]);
    while (*p != id)
        if (++p == end)
            return 0; // not interested

    return cluster_add_new(e, id);
}

struct endpoint* endpoint_get(uint16_t addr, uint8_t ep)
{
    struct node *n = node_find_by_nwk(addr);
    if (!n && !(n = node_new(addr)))
        return 0;

    struct endpoint *e = endpoint_find(n, ep);
    return e ? e : endpoint_new(n, ep);
}

struct endpoint* endp_find(uint16_t addr, int ep)
{
    return endpoint_find(node_find_by_nwk(addr), ep);
}

void endpoint_add_new(uint16_t addr, const uint8_t *eps, int count, uint16_t cluster)
{
    struct endpoint *e;
    while (count--) {
        if ((e = endpoint_get(addr, *eps++))) {
            // mark action?  - e.g. flags |= MADE_ENDPOINTS;
            cluster_add_new(e, cluster);
        }
    }
}

void fetch_run_steps(struct cluster *c)
{
    void run_step(struct cluster *c, const fetch_f *fetch, const uint8_t *rew)
    {
        uint8_t step;
        do {     // run current step, repeat if fetch updated
            emberAfCorePrintln("----------  run_step at step = %2X", c->fetch);
            fetch[step = c->fetch](c, c->ep->meter);
        } while (step != c->fetch);

        struct node *n = c->ep->node;
        if (n->unJoined && rew[0] && step > rew[0] && c->id != 0x019)
            emberAfCorePrint("%x:%x:%x step=%u, clearing unJoined\n", n->addr, c->ep->num, c->id, step), n->unJoined = 0;
    }

       const frt *cle = fr_table;
    // look for cluster Id match, run step(s) 
    while (cle < fr_table + sizeof(frt) / sizeof(fr_table[0])) {
        if ( cle->id == c->id) {
            emberAfCorePrintln("----------  fetch_run_steps running for clId = %2X", c->id);
            run_step(c, cle->f, cle->r);
            break;
        }
        cle++;
    }
}

// zmeter dependencies

uint8_t attr_length(uint8_t type)
{
    if ((type >= 0x08 && type <= 0x10) || (type >= 0x18 && type <= 0x31)) // general data, boolean, bitmap, unsigned, signed or enum
        return type % 8 + 1;
    else if (type == 0x38 || (type & ~1) == 0xE8) // floating point or cluster/attr ID
        return 2;
    else if (type == 0x39 || type == 0xEA || (type >= 0xE0 && type <= 0xE2)) // floating point, BACnet OID or time
        return 4;
    else if (type == 0x3A || type == 0xF0) // floating point or IEEE address
        return 8;
//    else if (type == 0x41 || type == 0x42) // octet or character string
//        return pstrlen(*p);
    else if (type == 0xF1) // security key
        return 16;
    return 0;
}

int smets_han(void) // TODO
{
    return 2;
}

void attr_range(struct cluster *c, int base, int count)
{
	uint16_t buf[16], got = 0;
	while (count--)
		buf[got++] = base++;

	emberAfFillCommandGlobalClientToServerReadAttributes(c->id, buf, got * 2);
	send_common(c, DO_ATTR);
}

int cmd_call(struct cluster *c, int id, const char *fmt, ...)
{
    uint8_t tmp[1536], *o = tmp, digits = 0, byte = 0;

    va_list l;
    va_start(l, fmt);
    if (fmt) while (1) {
        char c = *fmt++;
        if (c >= '0' && c <= '9')
            byte = byte << 4 | (c - '0'), digits++;
        else if (c >= 'A' && c <= 'F')
            byte = byte << 4 | (c - 'A' + 10), digits++;
        else if (digits)
            digits = 2, fmt--;

        if (digits == 2) {
            *o++ = byte;
            digits = byte = 0;
            continue;
        } else if (c == 0)
            break;

        if (c == 'b') // byte
            *o++ = va_arg(l,unsigned);
        else if (c == 'w') { // word
            unsigned w = va_arg(l, unsigned);
            *o++ = w;
            *o++ = w >> 8;
        } else if (c == 'l') { // long word
            unsigned w = va_arg(l, unsigned);
            *o++ = w;
            *o++ = w >> 8;
            *o++ = w >> 16;
            *o++ = w >> 24;
        } else if (c == 's') { // string
            char *s = va_arg(l,char*), *e = s;
            uint8_t *anchor = o++;
            if (e) while (*e)
                *o++ = *e++;
            *anchor = e - s;
        } else if (c == 'd') { // data block
            uint8_t *d = va_arg(l, uint8_t*);
            uint8_t *end = va_arg(l, uint8_t*);
            while (d < end)
                *o++ = *d++;
        }
    }
    va_end(l);

//    if (c->id == 0x704 && id == 0x02 || c->id == 0x019) // DDR = 0 for tunneling::CMD_CLIENT_TRANSFER_DATA and all OTA commands
//        emberAfSetDisableDefaultResponse(EMBER_AF_DISABLE_DEFAULT_RESPONSE_NONE);

    emberAfFillExternalBuffer(ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER, c->id, id, "b", tmp, o - tmp);
    return send_common(c, DO_CMD);
}

void utc_set(utc_t t)
{
}

utc_t utc_now(void)
{
    return 1; // subtract baseline?
}

int utc_decompose(uint32_t utc, uint8_t *mdhms)
{
    EmberAfTimeStruct tm;
    emberAfFillTimeStructFromUtc(utc, &tm);

    *mdhms++ = tm.month;
    *mdhms++ = tm.day;
    *mdhms++ = tm.hours;
    *mdhms++ = tm.minutes;
    *mdhms++ = tm.seconds;
    return tm.year;
}

utc_t utc_recompose(int year, uint8_t *mdhms)
{
	EmberAfTimeStruct tm = {year, mdhms[0], mdhms[1], mdhms[2], mdhms[3], mdhms[4]};
	return emberAfGetUtcFromTimeStruct(&tm);
}

int send_price_ack(struct zcmd *z, uint32_t ProviderID, uint32_t IssuerEventID, uint8_t PriceControl)
{
	emberAfFillCommandPriceClusterPriceAcknowledgement(ProviderID, IssuerEventID, emberAfGetCurrentTimeCallback(), PriceControl);
	return emberAfSendResponse();
}

void bind_do(struct cluster *c)
{
    EmberEUI64 me; // TODO aExtendedAddress?
    emberAfGetEui64(me);
    return;  // let's not get carried away here...
//    EmberStatus s = emberBindRequest(c->ep->node->addr, c->ep->node->ieee, c->ep->num, c->id, UNICAST_BINDING, me, 0, emberAfPrimaryEndpointForCurrentNetworkIndex(), EMBER_AF_DEFAULT_APS_OPTIONS);
//    finish_send(c, DO_BIND, s, emberGetLastAppZigDevRequestSequence());
}

uint8_t send_common(struct cluster *c, char type)
{
    emberAfSetCommandEndpoints(emberAfPrimaryEndpointForCurrentNetworkIndex(), c->ep->num);
    emberAfGetCommandApsFrame()->options &= ~EMBER_APS_OPTION_RETRY;
    EmberStatus s = emberAfSendCommandUnicast(EMBER_OUTGOING_DIRECT, c->ep->node->addr);

//    if (emberAfGetRadioChannel() >= 128)   // restore DDR = 1 for sub-ghz
//        emberAfSetDisableDefaultResponse(EMBER_AF_DISABLE_DEFAULT_RESPONSE_PERMANENT);

    return finish_send(c, type, s, emberAfGetLastSequenceNumber());
}


#ifdef IM_LIST_DEBUG
void show_nodes(char *label)
{
    struct node *n = nodes;
    emberAfCorePrintln("------- nodes: %2X  (%s)", n, label);
    while (n) {
        emberAfCorePrint("-------   ->  addr: %2X  ieee:", n->addr);
        for (int i=0;i<8;i++) emberAfCorePrint(" %X", n->ieee[i]);
        emberAfCorePrintln("  plke: %d  unJoined: %d   next: %2X  ", n->plke, n->unJoined, n->next);
        n = n->next;
    }
    emberAfCorePrintln("");
}

void show_clusters(char *label)
{
    struct cluster *c = clusters;
    emberAfCorePrintln("------- clusters: %2X  (%s)", c, label);
    while (c) {
        emberAfCorePrint("-------   ->  ep: %2X  id: %2X  ops: %2X" , c->ep, c->id, c->ops);
        if (c->ops) emberAfCorePrint("  ops->attr: %2X  ops->cmd: %2X  ops->def_rsp: %2X", c->ops->attr, c->ops->cmd, c->ops->def_rsp);
        emberAfCorePrintln("  fetch: %d  retry: %d   next: %2X  ", c->fetch, c->retry, c->next);
        c = c->next;
    }
    emberAfCorePrintln("");
}

void show_endpoints(char *label)
{
    struct endpoint *e = endpoints;
    emberAfCorePrintln("------- endpoints: %2X  (%s)", e, label);
    while (e) {
        emberAfCorePrintln("-------   ->  node: %2X  num: %d  meter: %2X  stall: %2X  profid: %2X  devid: %2X  rewind: %d  backoff: %d   next: %2X", 
                            e->node, e->num, e->meter, e->stall, e->profid, e->devid, e->rewind, e->backoff, e->next);
        e = e->next;
    }
    emberAfCorePrintln("");
}

/* 
show_meters()
*/

#endif
