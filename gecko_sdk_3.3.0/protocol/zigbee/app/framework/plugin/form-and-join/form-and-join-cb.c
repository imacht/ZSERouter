#include "af.h"

/** @brief Network Found
 *
 * This is called by the form-and-join library to notify the application of the
 * network found after a call to ::emberScanForJoinableNetwork() or
 * ::emberScanForNextJoinableNetwork(). See form-and-join documentation for
 * more information.
 *
 * @param networkFound   Ver.: always
 * @param lqi   Ver.: always
 * @param rssi   Ver.: always
 */
WEAK(void emberAfPluginFormAndJoinNetworkFoundCallback(EmberZigbeeNetwork *networkFound,
                                                       uint8_t lqi,
                                                       int8_t rssi))
{
}

/** @brief Unused Pan Id Found
 *
 * This function is called when the form-and-join library finds an unused PAN
 * ID that can be used to form a new network on.
 *
 * @param panId A randomly generated PAN ID without other devices on it.
 * Ver.: always
 * @param channel The channel where the PAN ID can be used to form a new
 * network. Ver.: always
 */
WEAK(void emberAfPluginFormAndJoinUnusedPanIdFoundCallback(EmberPanId panId,
                                                           uint8_t channel))
{
}
