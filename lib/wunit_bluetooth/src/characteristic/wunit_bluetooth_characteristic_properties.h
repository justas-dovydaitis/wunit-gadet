#ifndef __WUNIT_BLUETOOTH_CHARACTERISTIC_PROPERTIES_H__
#define __WUNIT_BLUETOOTH_CHARACTERISTIC_PROPERTIES_H__

class WUnitBluetoothCharacteristicProperties
{
public:
    ~WUnitBluetoothCharacteristicProperties(){};
    bool _hasReadPermision;
    bool _hasWritePermision;
    bool _isBroadcasting;
    bool _isNotifying;
    bool _isIndicated;
};

#endif // __WUNIT_BLUETOOTH_CHARACTERISTIC_PROPERTIES_H__