/* Gubbins from hm.c /   for handling endpoint lists & updating */

#define EMBER_SUCCESS (0x00u)

struct cluster* cluster_get(struct endpoint *e, uint16_t id);
struct endpoint* endpoint_get(uint16_t addr, uint8_t ep);
struct endpoint* endp_find(uint16_t addr, int ep);
void endpoint_add_new(uint16_t addr, const uint8_t *eps, int count, uint16_t cluster);
