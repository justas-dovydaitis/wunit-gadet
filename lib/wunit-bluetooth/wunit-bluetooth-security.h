#ifndef __WUNIT_BLUETOOTH_SECURITY_H__
#define __WUNIT_BLUETOOTH_SECURITY_H__

#include <Arduino.h>
#include <BLEDevice.h>

class BTSecurity : public BLESecurityCallbacks
{
    bool onConfirmPIN(uint32_t pin);
    void onPassKeyNotify(uint32_t pass_key);
    uint32_t onPassKeyRequest();
    bool onSecurityRequest();
    void onAuthenticationComplete(esp_ble_auth_cmpl_t cmpl);
};

#endif