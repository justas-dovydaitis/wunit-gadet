#include "Angle.h"
#include "Config/Config.h"
#include "IOConfig/IOConfig.h"

long angleCompensate;

Angle::Angle(uint8_t pinInput) : _pinInput(pinInput)
{
    _compensate = Config::getInstance()->getConfig().angleCompensate;
}

long Angle::getAngle()
{
    long angleValue = analogRead(_pinInput);

    long minAnalogReadValue = 0;
    long maxAnalogReadValue = 4095;

    long minAngleValue = -90;
    long maxAngleValue = 90;

    // map() changes range of analog value. Basically converts analog singal into degrees.
    long currentAngle = map(angleValue, minAnalogReadValue, maxAnalogReadValue, minAngleValue, maxAngleValue) + angleCompensate;

    return currentAngle;
}

void Angle::setCompensate(float compensate)
{
    angleCompensate = compensate;
}

void Angle::adjustCompensate(float compensateAdjustVal)
{
    angleCompensate += compensateAdjustVal;
}

void Angle::setAngleToZero()
{
    long currentAngle = getAngle();
    angleCompensate -= currentAngle;
}