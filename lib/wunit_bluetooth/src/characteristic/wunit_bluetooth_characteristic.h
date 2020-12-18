#ifndef __WUNIT_BLUETOOTH_CHARACTERISTIC_H__
#define __WUNIT_BLUETOOTH_CHARACTERISTIC_H__

#include <Arduino.h>

#include "wunit_bluetooth_characteristic_callbacks.h"
#include "wunit_bluetooth_characteristic_properties.h"

class WUnitBluetoothCharacteristic
{
public:
    WUnitBluetoothCharacteristic(uint16_t handle, WUnitBluetoothCharacteristicProperties properties);
    ~WUnitBluetoothCharacteristic();

    void setProperties(WUnitBluetoothCharacteristicProperties properties);
    void setValue(void *callback);

    String getValue();
    uint16_t getHandle();

private:
    uint16_t _handle;
    String _value;
    WUnitBluetoothCharacteristicProperties _properties;
    
    friend class WUnitBluetoothServer;
    friend class WUnitBluetoothService;
    friend class WUnitBluetoothCharacteristicMap;
};

#endif // __WUNIT_BLUETOOTH_CHARACTERISTIC_H__