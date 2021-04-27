#ifndef __ANALOG_SENSOR_H__
#define __ANALOG_SENSOR_H__

#include "Arduino.h"

const long minAnalogReadValue = 0;
const long maxAnalogReadValue = 4095;

template <typename T>
class AnalogSensor
{
protected:
    uint8_t _pinInput;

    long remapRangeFrom;
    long remapRangeTo;

public:
    AnalogSensor()
    {
        pinMode(_pinInput, INPUT);
    }

    T getValue()
    {
        long angleValue = analogRead(_pinInput);

        T value = map(angleValue, minAnalogReadValue, maxAnalogReadValue, remapRangeFrom, remapRangeTo);

        return value;
    }
};

#endif