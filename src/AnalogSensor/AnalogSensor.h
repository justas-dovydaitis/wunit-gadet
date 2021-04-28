#ifndef __ANALOG_SENSOR_H__
#define __ANALOG_SENSOR_H__

#include "Arduino.h"

template <typename T>
class AnalogSensor
{
protected:
    uint8_t _pinInput;

    float _remapRangeFromLow = 0;
    float _remapRangeFromHigh = 4095;

    float _remapRangeToHigh;
    float _remapRangeToLow;

    float _adjustment = 0;

public:
    AnalogSensor()
    {
        pinMode(_pinInput, INPUT);
    }

    T getValue()
    {
        long sensorValue = analogRead(_pinInput);

        float adjustmentInProportion = (_remapRangeFromHigh - _remapRangeFromLow) * (_adjustment / (_remapRangeToHigh - _remapRangeToLow));

        T value = map(sensorValue + adjustmentInProportion, _remapRangeFromLow, _remapRangeFromHigh, _remapRangeToLow, _remapRangeToHigh);

        return value;
    }
};

#endif