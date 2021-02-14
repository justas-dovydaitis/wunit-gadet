#ifndef __WUNIT_BLUETOOTH_CALLBACKS_H__
#define __WUNIT_BLUETOOTH_CALLBACKS_H__

#include <Arduino.h>
#include <BLEServer.h>

class PasswordCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic)
    {
        String newPasskeyValue = pCharacteristic->getValue().c_str();

        if (newPasskeyValue.length() == 6)
        {
            uint32_t newPasskey = atoi(newPasskeyValue.c_str());

            esp_ble_gap_set_security_param(ESP_BLE_SM_SET_STATIC_PASSKEY, &newPasskey, sizeof(uint32_t));
        }
        pCharacteristic->setValue("OK");
    }
};

#endif