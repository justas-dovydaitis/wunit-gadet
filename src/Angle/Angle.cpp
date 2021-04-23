#include "Angle.h"
#include "Config/Config.h"
#include "IOConfig/IOConfig.h"

long angleCompensate;

void setupAngle()
{
    angleCompensate = Config::getInstance()->angleCompensate();
}

long getCurrentAngle()
{
    long angleValue = analogRead(PIN_INPUT_ANGLE);

    long minAnalogReadValue = 0;
    long maxAnalogReadValue = 4095;

    long minAngleValue = -90;
    long maxAngleValue = 90;

    // map() changes range of analog value. Basically converts analog singal into degrees.
    long currentAngle = map(angleValue, minAnalogReadValue, maxAnalogReadValue, minAngleValue, maxAngleValue) + angleCompensate;

    return currentAngle;
}

void setAngleCompensate(float compensate)
{
    angleCompensate = compensate;
}

void adjustAngleCompensate(float compensateAdjustVal)
{
    angleCompensate += compensateAdjustVal;
}

void setCurrentAngleToZero()
{
    long currentAngle = getCurrentAngle();
    angleCompensate -= currentAngle;
}