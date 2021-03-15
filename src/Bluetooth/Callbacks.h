#ifndef __BLUETOOTH_CALLBACKS_H__
#define __BLUETOOTH_CALLBACKS_H__

#include <Arduino.h>
#include <EEPROM.h>
#include <BLEServer.h>

#include "EEPROMConstants.h"

class PasswordCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic);
};

#endif