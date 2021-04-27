#ifndef __ANGLE_H__
#define __ANGLE_H__

#include "AnalogSensor/AnalogSensor.h"
#include "Constants.h"
#include "Templates/Singleton.h"

#include <Arduino.h>

class Angle : public AnalogSensor<uint8_t>, public Singleton<Angle>
{
    friend class Singleton<Angle>;

protected:
    uint8_t _compensate = C_DEFAULT_ANGLE_COMPENSATE;

    Angle();

public:
    uint8_t getAngle();
    void setCompensate(float compensate);
    void adjustCompensate(float compensateAdjustVal);
    void setAngleToZero();
};

#endif