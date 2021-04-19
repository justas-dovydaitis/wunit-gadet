#include "State.h"

void AbstractState::turnOnOutput(uint8_t outputPin)
{
    digitalWrite(outputPin, HIGH);
}

void AbstractState::turnOffOutput(uint8_t outputPin)
{
    digitalWrite(outputPin, LOW);
}

void AbstractState::turnOnOutputWithTimeout(uint8_t outputPin, ulong timeout)
{
    turnOnOutput(outputPin);
    vTaskDelay(pdMS_TO_TICKS(timeout));
    turnOffOutput(outputPin);
}
void AbstractState::turnOnInterval(uint8_t outputPin, ulong interval)
{
    for (;;)
    {
        turnOnOutputWithTimeout(outputPin, (interval / 2));
        vTaskDelay(pdMS_TO_TICKS(interval / 2));
    }
}

void AbstractState::turnOnIntervalWithTimeout(uint8_t outputPin, ulong interval, ulong timeout)
{
    for (;;)
    {
        turnOnOutputWithTimeout(outputPin, (interval / 2));
        vTaskDelay(pdMS_TO_TICKS(interval / 2));
    }
}

AbstractState *pCurrentState = nullptr;

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
// TODO: Save last state to eeprom.