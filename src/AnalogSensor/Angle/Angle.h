#ifndef __ANGLE_H__
#define __ANGLE_H__

#include "AnalogSensor/AnalogSensor.h"
#include "Constants.h"
#include "Templates/Singleton.h"

#include <Arduino.h>

class Angle : public AnalogSensor<int16_t>, public Singleton<Angle>
{
    friend class Singleton<Angle>;

protected:
    Angle();

public:
    void setCompensate(float compensate);
    void adjustCompensate(float compensateAdjustVal);
    void setAngleToZero();
};

#endif