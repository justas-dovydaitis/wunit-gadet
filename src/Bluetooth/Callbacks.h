#ifndef __BLUETOOTH_CALLBACKS_H__
#define __BLUETOOTH_CALLBACKS_H__

#include "Bluetooth.h"

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include "esp_ota_ops.h"

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

class ControlCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic);
};

class ConfigCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic);
};

class UpdateOTACallbacks : public BLECharacteristicCallbacks
{
private:
    Bluetooth *_pBluetooth;

public:
    UpdateOTACallbacks(Bluetooth *bluetooth);
    void onWrite(BLECharacteristic *pCharacteristic);
};

#endif