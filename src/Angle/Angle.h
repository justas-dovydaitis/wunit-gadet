#ifndef __ANGLE_H__
#define __ANGLE_H__

#include <Arduino.h>

class Angle
{
private:
    long _compensate;
    uint8_t _pinInput;

public:
    Angle(uint8_t pinInput);

    long getAngle();
    void setCompensate(float compensate);
    void adjustCompensate(float compensateAdjustVal);
    void setAngleToZero();
};

#endif