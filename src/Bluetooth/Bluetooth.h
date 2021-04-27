#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#include "Templates/Singleton.h"

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>

class Bluetooth : public Singleton<Bluetooth>
{
    friend class Singleton<Bluetooth>;

protected:
    Bluetooth();

    bool _isConnected = false;

    BLEServer *_pBLEServer;
    BLEAdvertising *_pBLEAdvertising;

    BLEService *_pConfigService;
    BLEService *_pControlService;
    BLEService *_pDashboardService;

    BLECharacteristic *_pAngleCharacteristic;
    BLECharacteristic *_pGadgetsCharacteristic;
    BLECharacteristic *_pOdometerCharacteristic;
    BLECharacteristic *_pSpeedometerCharacteristic;
    BLECharacteristic *_pTachometerCharacteristic;

    BLECharacteristic *_pControlCharacteristic;

    BLECharacteristic *_pConfigCharacteristic;
    BLECharacteristic *_pPasswordCharacteristic;
    BLECharacteristic *_pUpdateCharacteristic;
    BLECharacteristic *_pOTAIdCharacteristic;
    BLECharacteristic *_pVersionCharacteristic;

    void setupBLESecurity();
    void setupBLEServices();
    void setupBLECharacteristics();

public:
    bool isConnected();
    void setConnected(bool connected);

    BLEAdvertising *getAdvertising();

    BLEService *getConfigService();
    BLEService *getDashboardService();
    BLEService *getControlService();

    BLECharacteristic *getAngleCharacteristic();
    BLECharacteristic *getOdometerCharacteristic();
    BLECharacteristic *getTachometerCharacteristic();
    BLECharacteristic *getSpeedometerCharacteristic();
};

#endif