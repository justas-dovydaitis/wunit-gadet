#include <wunit-angle.h>

WUnitAngle::WUnitAngle(uint8_t anglePin, uint8_t d1Pin, uint8_t d2Pin)
{
    _anglePin = anglePin;
    pinMode(anglePin, INPUT);
    _d1Pin = d1Pin;
    _d2Pin = d2Pin;
}

long WUnitAngle::getAngle()
{
    long angleValue = analogRead(_anglePin);

    long minAnalogReadValue = 0;
    long maxAnalogReadValue = 4095;

    long minAngleValue = -90;
    long maxAngleValue = 90;

    // map() changes range of analog value. Basically converts analog singal into degrees.
    long currentAngle = map(angleValue, minAnalogReadValue, maxAnalogReadValue, minAngleValue, maxAngleValue) + _angleCompensate;

    return currentAngle;
}

void WUnitAngle::setAngleCompensate(float compensate)
{
    _angleCompensate = compensate;
}

void WUnitAngle::adjustAngleCompensate(float compensateAdjustVal)
{
    _angleCompensate += compensateAdjustVal;
}

void WUnitAngle::setCurrentAngleToZero()
{
    long currentAngle = getAngle();
    _angleCompensate -= currentAngle;
}