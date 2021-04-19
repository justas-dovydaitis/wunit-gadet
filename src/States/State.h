#ifndef __STATE_H__
#define __STATE_H__

#include <Arduino.h>

#include "Controls/Controls.h"

#define LOCKED_STATE 0
#define UNLOCKED_STATE 1
#define IGNITION_STATE 2
#define RUNNING_STATE 3

class AbstractState
{
public:
    virtual void init() = 0;
    virtual void destroy() = 0;

    void turnOnOutput(uint8_t oututPin);
    void turnOffOutput(uint8_t oututPin);
    void turnOnOutputWithTimeout(uint8_t oututPin, ulong timeout);
    void turnOnInterval(uint8_t outputPin, ulong interval);
    void turnOnIntervalWithTimeout(uint8_t outputPin, ulong interval, ulong timeout);
};

extern AbstractState *pCurrentState;

void setState(AbstractState *pNewState);

#endif