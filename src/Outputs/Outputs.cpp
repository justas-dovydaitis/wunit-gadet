#include "Outputs.h"

const float defaultPWMFreq = 1000;

Outputs::Outputs()
{
    _pwm = Adafruit_PWMServoDriver();
    _pwm.begin();
    _pwm.setPWMFreq(defaultPWMFreq);
    int i = 0;
    while (i < 15)
    {
        _pins[i] = CLOSED;
        _pwm.setPin(i, _pins[i]);
        i++;
    }
}

void Outputs::setPinOn(uint8_t pin)
{
    _pwm.setPin(pin, OPEN);
    _pins[pin] = OPEN;
}
void Outputs::setPinOff(uint8_t pin)
{
    _pwm.setPin(pin, CLOSED);
    _pins[pin] = CLOSED;
}

void Outputs::pulsePin(uint8_t pin, long timeRise, long timeFall)
{
}

uint16_t Outputs::getOutputStatusBitmask()
{
    uint16_t bitmask = 0;

    for (int i = 0; i < 16; i++)
    {
        if (_pins[i])
        {
            bitmask += pow(2, i);
        }
    }
    return bitmask;
}