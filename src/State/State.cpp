#include "State.h"

AbstractState *pCurrentState = nullptr;

void setState(AbstractState *pNewState)
{
    Serial.println("Current state defined = " + (pCurrentState != nullptr));
    if (pCurrentState != nullptr)
    {
        pCurrentState->destroy();
    }
    pCurrentState = pNewState;

    pCurrentState->init();
}
