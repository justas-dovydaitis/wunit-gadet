#ifndef __SPEED_H__
#define __SPEED_H__

#include "AnalogSensor/AnalogSensor.h"
#include "Templates/Singleton.h"

class Speed : public AnalogSensor<uint16_t>, public Singleton<Speed>
{
    friend class Singleton<Speed>;

protected:
    Speed();
};

#endif