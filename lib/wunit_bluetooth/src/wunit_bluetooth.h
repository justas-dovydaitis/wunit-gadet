#ifndef __WUNIT_BLUETOOTH_H__
#define __WUNIT_BLUETOOTH_H__

#include <Arduino.h>

#include "server/wunit_bluetooth_server.h"

class WUnitBluetooth
{
private:
    Stream &_serial;
    int _statePin;
    int _pwrcPin;
    bool _debug;

    /***
     * Waits and reads response form BLE module.
     * SpinLock. Needs other solution I guess...
     * @returns true if ok, otherwise false
     */
    String readResponse();

public:
    ~WUnitBluetooth();
    /**
     * Constructor
     * @param serial Serial used for BLE communication.
     * @param statePin Indicates if there is connectivity with other device.
     * @param pwrcPin Sleep control pin.
     * @param debug Use Serial for debugging.
     */
    WUnitBluetooth(HardwareSerial &serial, int statePin, int pwrcPin, bool debug);
    /**
     * Sets a password to bluetooth module.
     * @param newPass new password to set.
     */
    void setPassword(String newPass);

    /**
     * Sets new name to Bluetooth module.
     * @param newName New name to set.
     */
    void setName(String newName);

    /**
     * Reboots module
     */
    void restart();

    /**
     * Applies factory reset.
     */
    void reset();

    /**
     * Checks whether there is BT connection.
     * @returns true if there is connection. False if there's not.
     */
    bool isConnected();

    /**
     * Checks whether bluetooth has unread stream.
     * @returns True if available or false if it's not.
     */
    bool isAvailable();

    /**
     * Closes bluetooth connection.
     */
    void disconnect();

    /**
     * Enters AT mode.
     */
    void enterATMode();

    void write(char character);

    int read();

    String readString();
};

#endif // __WUNIT_BLUETOOTH_H__