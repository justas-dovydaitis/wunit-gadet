#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>

extern BLEServer *pBLEServer;
extern BLEAdvertising *pBLEAdvertising;

extern BLEService *pConfigService;
extern BLEService *pControlService;
extern BLEService *pDashboardService;

extern BLECharacteristic *pAngleCharacteristic;
extern BLECharacteristic *pGadgetsCharacteristic;
extern BLECharacteristic *pOdometerCharacteristic;
extern BLECharacteristic *pSpeedometerCharacteristic;
extern BLECharacteristic *pTachometerCharacteristic;

extern BLECharacteristic *pControlCharacteristic;

extern BLECharacteristic *pConfigCharacteristic;
extern BLECharacteristic *pPasswordCharacteristic;

void setupBLESecurity();
void setupBLEServices();
void setupBLECharacteristics();
void setupBLE();

#endif