#include "Config/Config.h"
#include "State.h"

AbstractState *pCurrentState = nullptr;
Preferences prefferences;

void AbstractState::setInitCommand(CommandInterface *pCommand)
{
    _pInitRoutine = pCommand;
}
void AbstractState::setDestroyCommand(CommandInterface *pCommand)
{
    _pDestroyRoutine = pCommand;
}

uint16_t AbstractState::getStateId()
{
    return _currentStateId;
}

void AbstractState::init()
{
    Config::getInstance()->setLastState(_currentStateId);
    if (_pInitRoutine != nullptr)
    {
        _pInitRoutine->execute();
    }
    onInit();
}

void AbstractState::destroy()
{
    if (_pDestroyRoutine != nullptr)
    {
        _pDestroyRoutine->execute();
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