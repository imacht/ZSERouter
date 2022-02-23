/* Gubbins from hm.c /   for handling endpoint etc. lists & updating */

#include <zmeter.h>
#include <stdlib.h>
#include "gubbins.h"
#include "zap-id.h"

#include "app/framework/include/af.h"

/* debug use */
extern struct node *nodes;
extern struct endpoint *endpoints;
extern struct cluster *clusters;
/*****/

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
        emberAfCorePrint("-------   ->  node: %2X  num: %d  meter: %2X  stall: %2X  profid: %2X  devid: %2X  rewind: %d  backoff: %d   next: %2X", 
                            e->node, e->num, e->meter, e->stall, e->profid, e->devid, e->rewind, e->backoff, e->next);
        e = e->next;
    }
    emberAfCorePrintln("");
}
