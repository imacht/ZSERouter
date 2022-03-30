/* Gubbins from hm.c /   for handling endpoint lists & updating */

#include "app/framework/include/af.h"
//#define EMBER_SUCCESS (0x00u)

typedef enum {
    UNINITIALISED,  // 0
    STARTING,
    STOPPING,
    REBOOT,
    SCANNING,
    START_KE,       // 5
    FIND_METERS,
    FIND_PRICES,
    GET_SDRS,
    GET_IEEE,
    DO_PLKE,        // 10
//TODO:    FIND_OTA,
    IDLE,
    DO_ATTR,
    DO_CMD
} SxpState_t;

void prepare_ack_ddr(int subghz);
bool no_tc_link_key(void);
struct cluster* clus_find_af(EmberAfClusterCommand *af);
struct cluster* cluster_get(struct endpoint *e, uint16_t id);
struct endpoint* endpoint_get(uint16_t addr, uint8_t ep);
struct endpoint* endp_find(uint16_t addr, int ep);
void endpoint_add_new(uint16_t addr, const uint8_t *eps, int count, uint16_t cluster);
void fetch_run_steps(struct cluster *c);
uint8_t attr_length(uint8_t type);
int smets_han(void);
int cmd_call(struct cluster *c, int id, const char *fmt, ...);
utc_t utc_now(void);
int utc_decompose(utc_t utc, uint8_t *mdhms);
int send_price_ack(struct zcmd *z, uint32_t ProviderID, uint32_t IssuerEventID, uint8_t PriceControl);
//void bind_do(struct cluster *c);
uint8_t finish_send(struct cluster *c, char type, EmberStatus s, uint8_t seq);
uint8_t send_common(struct cluster *c, char type);
//void utc_set(utc_t t);

void show_nodes(char *);
void show_clusters(char *label);
void show_endpoints(char *label);
void show_meter(char *label, struct endpoint *e);

// Time

/** Set up metro event to tick in 1 second.
 \param e metro event
 \return Current UTC time */
uint32_t time_run(sl_zigbee_event_t *e);
