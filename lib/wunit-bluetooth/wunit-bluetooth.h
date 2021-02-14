#ifndef __WUNIT_BLUETOOTH_H__
#define __WUNIT_BLUETOOTH_H__

#include <BLEDevice.h>

#include <BLEServer.h>
#include <esp_gap_ble_api.h>

#include <wunit-bluetooth-calbacks.h>
#include <wunit-bluetooth-security.h>
#include <wunit-bluetooth-uuids.h>


#define DEFAULT_PASSKEY 123456
#define ESP_BLE_OOB_DISABLE 0

class WUnitBluetooth
{
private:
    BLEServer *pServer;

    uint32_t _passkey;

    void registerServicesAndCharacteristics();
    void configureSecurity();

public:
    ~WUnitBluetooth();
    WUnitBluetooth();

    void setPasskey(uint32_t newPasskey);
};

#endif