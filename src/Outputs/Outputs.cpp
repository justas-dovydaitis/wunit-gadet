#include "Outputs.h"

const float defaultPWMFreq = 1000;

Outputs::Outputs()
{
    _pwm = Adafruit_PWMServoDriver();
    _pwm.begin();
    _pwm.setPWMFreq(defaultPWMFreq);
    int i = 0;
    do
        _pwm.setPin(i++, CLOSED);
    while (i < 15);
}

void Outputs::setPinOn(uint8_t pin)
{
    _pwm.setPin(pin, OPEN);
}
void Outputs::setPinOff(uint8_t pin)
{
    _pwm.setPin(pin, CLOSED);
}

void Outputs::pulsePin(uint8_t pin, long timeRise, long timeFall)
{
}

uint16_t Outputs::getOutputStatusBitmask()
{
    uint16_t bitmask = 0;

    for (int i = 0; i < 16; i++)
    {
        bitmask = bitmask << 1;
        if (_pwm.getPWM(i))
        {
            bitmask++;
        }
    }
    return bitmask;
}