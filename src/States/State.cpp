#include "State.h"
#include <Preferences.h>

AbstractState *pCurrentState = nullptr;
Preferences prefferences;

void AbstractState::saveState()
{
    prefferences.begin("wunit");

    prefferences.putUShort("lastState", _currentStateId);

    prefferences.end();
}
uint16_t AbstractState::getStateId()
{
    return _currentStateId;
}

void setState(AbstractState *pNewState)
{
    Serial.println("IS CURRENT STATE DEFINED: " + (pCurrentState != nullptr));
    if (pCurrentState != nullptr)
    {
        pCurrentState->destroy();
    }
    pCurrentState = pNewState;
    pCurrentState->init();
}