#include "State.h"
#include <Preferences.h>

AbstractState *pCurrentState = nullptr;
Preferences prefferences;

void AbstractState::setInitCommand(CommandInterface *pCommand)
{
    _pInitCommand = pCommand;
}
void AbstractState::setDestroyCommand(CommandInterface *pCommand)
{
    _pDestroyCommand = pCommand;
}

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

void AbstractState::init()
{
    saveState();
    if (_pInitCommand != nullptr)
    {
        _pInitCommand->execute();
    }
    onInit();
}

void AbstractState::destroy()
{
    if (_pDestroyCommand != nullptr)
    {
        _pDestroyCommand->execute();
    }
    onDestroy();
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