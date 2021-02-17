#ifndef __WUNIT_ANGLE_H__
#define __WUNIT_ANGLE_H__

#include <Arduino.h>

#define RADIAN 57.292779524

class WUnitAngle
{
private:
    uint8_t _anglePin;
    uint8_t _d1Pin;
    uint8_t _d2Pin;

    int _angleCompensate = 0;

public:
    WUnitAngle(uint8_t anglePin, uint8_t d1Pin, uint8_t d2Pin);
    long getAngle();
    void setAngleCompensate(float compensate);
    void adjustAngleCompensate(float compensateAdjustVal);
    void setCurrentAngleToZero();
};

#endif