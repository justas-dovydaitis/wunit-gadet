#include "Bluetooth/Bluetooth.h"
#include "InitState.h"
#include "IgnitionState.h"
#include "LockedState.h"
#include "RunningState.h"
#include "UnlockedState.h"

#include <Preferences.h>

void InitState::init()
{
    setupIO();

    uint16_t lastState;
    bool unlocked = Bluetooth::getInstance()->isConnected() || _keyUnlocked;

    Preferences preferences;
    preferences.begin("wunit");
    lastState = preferences.getUShort("lastState");
    preferences.end();

    if (unlocked)
    {
        switch (lastState)
        {
        case StateId_t::RUNNING_STATE:

            setState(new RunningState);
            break;

        case StateId_t::UNLOCKED_STATE:
            setState(new UnlockedState);
            break;

        case StateId_t::IGNITION_STATE:
            setState(new IgnitionState);
            break;
        }
    }
    else
    {
        setState(new LockedState);
    }
}
void InitState::destroy()
{
}