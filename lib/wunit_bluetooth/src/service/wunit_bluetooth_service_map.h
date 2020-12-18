#ifndef __WUNIT_BLUETOOTH_SERVICE_MAP_H__
#define __WUNIT_BLUETOOTH_SERVICE_MAP_H__

#include <Arduino.h>
#include <map>

#include "wunit_bluetooth_service.h"

class WUnitBluetoothServiceMap
{
private:
    std::map<uint16_t, WUnitBluetoothService *> _handleMap;
    std::map<WUnitBluetoothService *, String>::iterator _iterator;

public:
    WUnitBluetoothService *getService(uint16_t handle);
    void setService(uint16_t handle, WUnitBluetoothService *service);

    WUnitBluetoothService *getFirst();
    WUnitBluetoothService *getNext();

    void removeService(WUnitBluetoothService *service);
    int getRegisteredServiceCount();

    String toString();
};

#endif // __WUNIT_BLUETOOTH_SERVICE_MAP_H__