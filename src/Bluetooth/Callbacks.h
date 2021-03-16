#ifndef __BLUETOOTH_CALLBACKS_H__
#define __BLUETOOTH_CALLBACKS_H__

#include <Arduino.h>
#include <EEPROM.h>
#include <BLEServer.h>

#include "EEPROMConstants.h"

class ServerCallbacks : public BLEServerCallbacks
{
    void onConnect(BLEServer *pServer);
    void onConnect(BLEServer *pServer, esp_ble_gatts_cb_param_t *param);
    
    void onDisconnect(BLEServer *pServer);
};

class PasswordCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic);
};

#endif