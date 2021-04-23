#ifndef __STATE_H__
#define __STATE_H__

#include <Arduino.h>

#include "Controls/Controls.h"

enum StateId_t : uint16_t
{
    LOCKED_STATE = 0,
    UNLOCKED_STATE = 1,
    IGNITION_STATE = 2,
    RUNNING_STATE = 3,
    CONFIG_STATE = 4,
    INIT_STATE = 5,
    UNKNOWN_STATE = 9,
};

class AbstractState
{
protected:
    const uint16_t _currentStateId = StateId_t::UNKNOWN_STATE;

public:
    virtual void init() = 0;
    virtual void destroy() = 0;

    void saveState();
    uint16_t getStateId();
};

extern AbstractState *pCurrentState;

void setState(AbstractState *pNewState);

#endif