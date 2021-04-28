#ifndef __STATE_H__
#define __STATE_H__

#include "AnalogSensor/Angle/Angle.h"
#include "Bluetooth/Bluetooth.h"
#include "Controls/Controls.h"
#include "Commands/CompositeCommand.h"
#include "IOConfig/IOConfig.h"

enum StateId_t : uint16_t
{
    LOCKED_STATE = 0,
    UNLOCKED_STATE = 1,
    IGNITION_STATE = 2,
    RUNNING_STATE = 3,
    CONFIG_STATE = 4,
    INIT_STATE = 5,
    CRASHED_STATE = 6,
    UNKNOWN_STATE = 9,
};

class AbstractState
{
protected:
    const uint16_t _currentStateId = StateId_t::UNKNOWN_STATE;

    CommandInterface *_pInitRoutine = nullptr;
    CommandInterface *_pDestroyRoutine = nullptr;

    bool _keyUnlocked = false;

    virtual void onInit() = 0;
    virtual void onDestroy() = 0;

public:
    void init();
    void destroy();

    void setInitCommand(CommandInterface *pCommand);
    void setDestroyCommand(CommandInterface *pCommand);

    uint16_t getStateId();
};

extern AbstractState *pCurrentState;

void setState(AbstractState *pNewState);

#endif