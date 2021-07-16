#ifndef __TACH_H__
#define __TACH_H__

#include "AnalogSensor/AnalogSensor.h"
#include "Templates/Singleton.h"

class RPM : public AnalogSensor<uint16_t>, public Singleton<RPM>
{
    friend class Singleton<RPM>;

protected:
    RPM();
};

#endif