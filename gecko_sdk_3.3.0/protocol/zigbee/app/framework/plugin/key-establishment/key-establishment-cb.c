#include "af.h"

/** @brief Key Establishment
 *
 * A callback by the key-establishment code to indicate an event has occurred.
 * For error codes this is purely a notification.  For non-error status codes
 * (besides LINK_KEY_ESTABLISHED), it is the application's chance to allow or
 * disallow the operation.  If the application returns true then the key
 * establishment is allowed to proceed.  If it returns false, then key
 * establishment is aborted.  LINK_KEY_ESTABLISHED is a notification of success.
 *
 * @param status   Ver.: always
 * @param amInitiator   Ver.: always
 * @param partnerShortId   Ver.: always
 * @param delayInSeconds   Ver.: always
 */
WEAK(bool emberAfPluginKeyEstablishmentEventCallback(EmberAfKeyEstablishmentNotifyMessage status,
                                                     bool amInitiator,
                                                     EmberNodeId partnerShortId,
                                                     uint8_t delayInSeconds))
{
  return true;
}

/** @brief Key Establishment Inter Pan
 *
 * A callback by the key-establishment code to indicate an event has occurred.
 * For error codes this is purely a notification.  For non-error status codes
 * (besides LINK_KEY_ESTABLISHED), it is the application's chance to allow or
 * disallow the operation.  If the application returns true then the key
 * establishment is allowed to proceed.  If it returns false, then key
 * establishment is aborted.  LINK_KEY_ESTABLISHED is a notification of success.
 *
 * @param status   Ver.: always
 * @param amInitiator   Ver.: always
 * @param panId   Ver.: always
 * @param eui64   Ver.: always
 * @param delayInSeconds   Ver.: always
 */
WEAK(bool emberAfPluginKeyEstablishmentInterPanCallback(EmberAfKeyEstablishmentNotifyMessage status,
                                                        bool amInitiator,
                                                        EmberPanId panId,
                                                        const EmberEUI64 eui64,
                                                        uint8_t delayInSeconds))
{
  return true;
}
