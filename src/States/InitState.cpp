#include "Bluetooth/Bluetooth.h"
#include "InitState.h"
#include "IgnitionState.h"
#include "LockedState.h"
#include "RunningState.h"
#include "UnlockedState.h"

const bool engineRunning = false;
const bool btConnected = false;
const bool keyUnlocked = false;
const bool lastState = 1;

void InitState::init()
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

    case StateId_t ::LOCKED_STATE:
        setState(new LockedState);
    }
}
void InitState::destroy()
{
}