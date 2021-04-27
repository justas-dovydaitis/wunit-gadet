#ifndef __TACH_H__
#define __TACH_H__

#include "AnalogSensor/AnalogSensor.h"
#include "Templates/Singleton.h"

class Tach : public AnalogSensor<uint16_t>, public Singleton<Tach>
{
    friend class Singleton<Tach>;

protected:
    Tach();
};

#endif