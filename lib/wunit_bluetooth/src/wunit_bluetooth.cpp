#include "wunit_bluetooth.h"

WUnitBluetooth::WUnitBluetooth(HardwareSerial &serial, int statePin, int breakPin, bool debug = false) : _serial(serial)
{
    serial.begin(115200);
    _serial = serial;

    _statePin = statePin;
    pinMode(_statePin, INPUT);

    _pwrcPin = _pwrcPin;
    pinMode(_pwrcPin, OUTPUT);
    digitalWrite(_pwrcPin, HIGH);

    _debug = debug;
}

void WUnitBluetooth::setPassword(String newPass)
{
    Serial.println("ISCEN");
    _serial.print("AT+ISCEN0");
    readResponse();
    _serial.print("AT+ISCEN");
    readResponse();

    Serial.println("PASS");
    _serial.print("AT+PASS" + newPass);
    readResponse();
    _serial.print("AT+PASS");
    readResponse();

    restart();
}

void WUnitBluetooth::setName(String newName)
{
    Serial.println("NAME");
    _serial.print("AT+NAME" + newName + "\r\n");
    readResponse();
}

void WUnitBluetooth::restart()
{
    _serial.print("AT+RESET\r\n");
}

bool WUnitBluetooth::isConnected()
{
    return digitalRead(_statePin);
}

void WUnitBluetooth::write(char character)
{
    _serial.write(character);
}

String WUnitBluetooth::readString()
{
    bool isDataExpected = true;

    String data = "";

    while (isDataExpected)
    {
        if (_serial.available())
        {
            data = _serial.readString();
            isDataExpected = false;
        }
    }
    return data;
}

int WUnitBluetooth::read()
{
    return _serial.read();
}

bool WUnitBluetooth::isAvailable()
{
    return _serial.available();
}

void WUnitBluetooth::disconnect()
{
    // May not be supported in this shitty module.
}

String WUnitBluetooth::readResponse()
{
    bool isResponseExpected = true;

    String response = "";

    while (isResponseExpected)
    {
        if (_serial.available())
        {
            response = _serial.readString();
            isResponseExpected = false;
        }
    }

    return response;
}
