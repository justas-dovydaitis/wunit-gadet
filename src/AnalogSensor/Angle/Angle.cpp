#include "Angle.h"
#include "Config/Config.h"
#include "IOConfig/IOConfig.h"

Angle::Angle()
{
    _pinInput = C_ANGLE_INPUT_PIN;
    _adjustment = 4;
    _remapRangeToHigh = 90;
    _remapRangeToLow = -90;
    _remapRangeFromLow = 0 +300; 
    _remapRangeFromHigh = 4095-300;
    // _compensate = Config::getInstance()->getValue('constant');
}

void Angle::setCompensate(float compensate)
{
    _adjustment = compensate;
}

void Angle::adjustCompensate(float compensateAdjustVal)
{
    _adjustment += compensateAdjustVal;
}

void Angle::setAngleToZero()
{
    long currentAngle = getValue();
    _adjustment -= currentAngle;
}