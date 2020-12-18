#ifndef __WUNIT_BLUETOOTH_SERVICE_H__
#define __WUNIT_BLUETOOTH_SERVICE_H__

#include <Arduino.h>

#include "../server/wunit_bluetooth_server.h"

#include "../characteristic/wunit_bluetooth_characteristic.h"
#include "../characteristic/wunit_bluetooth_characteristic_map.h"

class WUnitBluetoothService
{
public:
    WUnitBluetoothCharacteristic *createCharacteristic(uint16_t handle, uint32_t properties);
    WUnitBluetoothCharacteristic *getCharacteristic(uint16_t handle);

    void addCharacteristic(WUnitBluetoothCharacteristic *characteristic);
    void removeCharacteristic(uint16_t handle);

    uint16_t getHandle();

    String toString();

private:
    WUnitBluetoothService(uint16_t handle);

    uint16_t handle;
    WUnitBluetoothCharacteristicMap _characteristicMap;
    WUnitBluetoothCharacteristic *_lastCreatedCharacteristic = nullptr;

    friend class WUnitBluetoothServer;
    friend class WUnitBluetoothServiceMap;
    friend class WUnitBluetoothCharacteristic;

    // WUnitBluetoothServer *_server = nullptr;

    WUnitBluetoothCharacteristic *getLastCreatedCharacteristic();
};
#endif // __WUNIT_BLUETOOTH_SERVICE_H__