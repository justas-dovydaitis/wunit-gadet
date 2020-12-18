#ifndef __WUNIT_BLUETOOTH_SERVER_H__
#define __WUNIT_BLUETOOTH_SERVER_H__

#include <Arduino.h>

#include "wunit_bluetooth_server_callbacks.h"

#include "../service/wunit_bluetooth_service.h"
#include "../service/wunit_bluetooth_service_map.h"

class WUnitBluetoothServer
{
public:
    WUnitBluetoothServer();
    
    WUnitBluetoothService *createService(uint16_t handle);
    WUnitBluetoothService *getService(uint16_t handle);
    void removeService(WUnitBluetoothService *service);

    void setCallbacks(WUnitBluetoothServerCallbacks *callbacks);
    void startAdvertising();

private:
    WUnitBluetoothServiceMap _serviceMap;
    WUnitBluetoothServerCallbacks *_serverCallbacks = nullptr;

    friend class WUnitBluetoothService;
    friend class WUnitBluetoothCharacteristic;
};

#endif // __WUNIT_BLUETOOTH_SERVER_H__