#include "Outputs.h"

Outputs *Outputs::_pInstance = nullptr;

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

Outputs *Outputs::getInstance()
{
    if (_pInstance == nullptr)
    {
        _pInstance = new Outputs();
    }
    return _pInstance;
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
