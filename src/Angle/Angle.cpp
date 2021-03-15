#include "Angle.h"

long angleCompensate;

void setupAngle()
{
    angleCompensate = DEFAULT_ANGLE_COMPENSATE;
}

long getCurrentAngle()
{
    long angleValue = analogRead(ANGLE_PIN);

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