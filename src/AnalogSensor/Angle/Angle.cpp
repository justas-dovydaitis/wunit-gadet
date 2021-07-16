#include "Angle.h"
#include "Config/Config.h"
#include "IOConfig/IOConfig.h"

const uint16_t C_LEAN_MAX_VALUE = 90;
const uint C_ANALOG_VALUE_RANGE_ADJUSTMENT = 300;

Angle::Angle()
{
    _pinInput = C_ANGLE_INPUT_PIN;
    _adjustment = Config::getInstance()->getAngleCompensate();
    _remapRangeToHigh = C_LEAN_MAX_VALUE;
    _remapRangeToLow = -C_LEAN_MAX_VALUE;
    _remapRangeFromLow = 0 + C_ANALOG_VALUE_RANGE_ADJUSTMENT;
    _remapRangeFromHigh = 4095 - C_ANALOG_VALUE_RANGE_ADJUSTMENT;
}

void Angle::setCompensate(float compensate)
{
    _adjustment = compensate;
    Config::getInstance()->setAngleCompensate(_adjustment);
}

void Angle::adjustCompensate(float compensateAdjustVal)
{
    _adjustment += compensateAdjustVal;
    Config::getInstance()->setAngleCompensate(_adjustment);
}

void Angle::setAngleToZero()
{
    long currentAngle = getValue();
    _adjustment -= currentAngle;
    Config::getInstance()->setAngleCompensate(_adjustment);
}