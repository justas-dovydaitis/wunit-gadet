#ifndef __WUNIT_BLUETOOTH_CHARACTERISTIC_CALLBACKS_H__
#define __WUNIT_BLUETOOTH_CHARACTERISTIC_CALLBACKS_H__


class WUnitBluetoothCharacteristic;
class WUnitBluetoothCharacteristicCallbacks
{
public:
    virtual ~WUnitBluetoothCharacteristicCallbacks();
    virtual void onRead(WUnitBluetoothCharacteristic *characteristic);
    virtual void onWrite(WUnitBluetoothCharacteristic *characteristic);
};

#endif // __WUNIT_BLUETOOTH_CHARACTERISTIC_CALLBACKS_H__