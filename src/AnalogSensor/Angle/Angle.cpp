#include "Angle.h"
#include "Config/Config.h"
#include "IOConfig/IOConfig.h"

Angle::Angle()
{
    _pinInput = C_ANGLE_INPUT_PIN;
    remapRangeFrom = -90;
    remapRangeTo = 90;
    // _compensate = Config::getInstance()->getValue('constant');
}

uint8_t Angle::getAngle()
{
    return getValue() - _compensate;
}

void Angle::setCompensate(float compensate)
{
    _compensate = compensate;
}

void Angle::adjustCompensate(float compensateAdjustVal)
{
    _compensate += compensateAdjustVal;
}

void Angle::setAngleToZero()
{
    long currentAngle = getAngle();
    _compensate -= currentAngle;
}