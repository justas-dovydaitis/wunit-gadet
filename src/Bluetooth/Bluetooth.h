#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>

#include "Security.h"
#include "Callbacks.h"

#define CONFIG_SERVICE_UUID "25be9010-7a82-11eb-9439-0242ac130002"
#define DASHBOARD_SERVICE_UUID "213860ca-7a82-11eb-9439-0242ac130002"

#define PASSKEY_CHARACTERISTIC_UUID "1b4b6220-7a82-11eb-9439-0242ac130002"
#define ANGLE_CHARACTERISTIC_UUID "d8925800-7a7f-11eb-9439-0242ac130002"
#define TACHOMETER_CHARACTERISTIC_UUID "f606b17c-7a81-11eb-9439-0242ac130002"
#define SPEEDOMETER_CHARACTERISTIC_UUID "fa034f9c-7a81-11eb-9439-0242ac130002"
#define ODOMETER_CHARACTERISITC_UUID "95265482-7a97-11eb-9439-0242ac130002"
#define STARTER_CHARACTERISTIC_UUID "6c6774a4-7a97-11eb-9439-0242ac130002"
#define LEFT_TURN_CHARASTERISTIC_UUID "7aadd364-7a97-11eb-9439-0242ac130002"
#define RIGHT_TURN_CHARACTERISTIC_UUID "7e065dec-7a97-11eb-9439-0242ac130002"
#define HORN_CHARACTERISTIC_UUID "80f2379c-7a97-11eb-9439-0242ac130002"
#define BRAKE_CHARACTERISTIC_UUID "838a8b30-7a97-11eb-9439-0242ac130002"
#define LIGHT_CHARACTERISTIC_UUID "877679fc-7a97-11eb-9439-0242ac130002"
#define HIGHT_BEAM_CHARACTERISTIC_UUID "89c3b2a6-7a97-11eb-9439-0242ac130002"
#define IGNITION_CHARACTERISTIC_UUID "8c964d90-7a97-11eb-9439-0242ac130002"
#define MARKERS_CHARACTERISTIC_UUID "8f29c3c0-7a97-11eb-9439-0242ac130002"
#define AUX_1_CHARACTERISTIC_UUID "916e877e-7a97-11eb-9439-0242ac130002"
#define AUX_2_CHARACTERISTIC_UUID "9372d0d4-7a97-11eb-9439-0242ac130002"

#define DEFAULT_BLUETOOTH_PASSKEY 123456


extern BLEServer *pBLEServer;
extern BLEAdvertising *pBLEAdvertinsing;

extern BLEService *pConfigService;
extern BLEService *pDashboardService;

extern BLECharacteristic *pAngleCharacteristic;
extern BLECharacteristic *pSpeedometerCharacteristic;
extern BLECharacteristic *pTachometerCharacteristic;
extern BLECharacteristic *pOdometerCharacteristic;

extern BLECharacteristic *pPasswordCharacteristic;

extern void setupBLESecurity();
extern void setupBLEServices();
extern void setupBLECharacteristics();
extern void setupBLE();

#endif