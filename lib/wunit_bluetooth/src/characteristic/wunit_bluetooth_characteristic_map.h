#ifndef __WUNIT_BLUETOOTH_CHARACTERISTIC_MAP_H__
#define __WUNIT_BLUETOOTH_CHARACTERISTIC_MAP_H__

 #include <ArduinoSTL.h>
#include <map>

#include "wunit_bluetooth_characteristic.h"

class WUnitBluetoothCharacteristicMap
{
public:
    void setCharacteristic(uint16_t handle, WUnitBluetoothCharacteristic *pCharacteristic);
    WUnitBluetoothCharacteristic *getCharacteristic(uint16_t handle);
    WUnitBluetoothCharacteristic *getFirst();
    WUnitBluetoothCharacteristic *getNext();
    String toString();

private:
    std::map<WUnitBluetoothCharacteristic *, uint16_t> _characteristicMap;
    std::map<WUnitBluetoothCharacteristic *, std::string>::iterator _iterator;
};

#endif // __WUNIT_BLUETOOTH_CHARACTERISTIC_MAP_H__