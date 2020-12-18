#ifndef __WUNIT_BLUETOOTH_SERVER_CALLBACKS_H__
#define __WUNIT_BLUETOOTH_SERVER_CALLBACKS_H__


class WUnitBluetoothServer;
class WUnitBluetoothServerCallbacks
{
public:
    virtual ~WUnitBluetoothServerCallbacks(){};

    virtual void onConnect(WUnitBluetoothServer *server);
    virtual void onDisconnect(WUnitBluetoothServer *server);
};

#endif // __WUNIT_BLUETOOTH_SERVER_CALLBACKS_H__