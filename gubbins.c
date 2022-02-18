/* Gubbins from hm.c /   for handling endpoint etc. lists & updating */

#include <zmeter.h>
#include <stdlib.h>
#include "gubbins.h"
#include "zap-id.h"

/* default defs to match externs in zmeter.h */
void* zalloc(size_t bytes) { return calloc(bytes,1); }
void dbgf(const char *fmt, ...) { }

// zmeter compatibility

uint8_t ieee_from_nwk(uint16_t nwk, uint8_t *out)
{
	return EMBER_SUCCESS == emberLookupEui64ByNodeId(nwk, out);
}

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

