#ifndef __OUTPUTS_H__
#define __OUTPUTS_H__

#include "templates/Singleton.h"

#include <Adafruit_PWMServoDriver.h>

class Outputs : public Singleton<Outputs>
{
    friend class Singleton<Outputs>;

protected:
    Outputs();

    Adafruit_PWMServoDriver _pwm;
    static void pulsePin(uint8_t pin, long timeRise, long timeFall);

public:
    void setPinOn(uint8_t pin);
    void setPinOff(uint8_t pin);

    uint16_t getOutputStatusBitmask();
    uint16_t OPEN = 4095;
    uint16_t CLOSED = 0;
};

#endif