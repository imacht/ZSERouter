/* Gubbins from hm.c /   for handling endpoint lists & updating */

#define EMBER_SUCCESS (0x00u)

struct endpoint* endpoint_get(uint16_t addr, uint8_t ep);
void endpoint_add_new(uint16_t addr, const uint8_t *eps, int count, uint16_t cluster);

