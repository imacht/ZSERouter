/* Gubbins from hm.c /   for handling endpoint lists & updating */

#include <zmeter.h>
#include <stdlib.h>
#include "gubbins.h"

/* default defs to match externs in zmeter.h */
void* zalloc(size_t bytes) { return calloc(bytes,1); }
void dbgf(const char *fmt, ...) { }

// zmeter compatibility

uint8_t ieee_from_nwk(uint16_t nwk, uint8_t *out)
{
	return EMBER_SUCCESS == emberLookupEui64ByNodeId(nwk, out);
}

struct endpoint* endpoint_get(uint16_t addr, uint8_t ep)
{
	struct node *n = node_find_by_nwk(addr);
	if (!n && !(n = node_new(addr)))
		return 0;

	struct endpoint *e = endpoint_find(n, ep);
	return e ? e : endpoint_new(n, ep);
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

