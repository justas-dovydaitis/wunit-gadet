#include "ISRs.h"

#include "State/State.h"
#include "Tasks/Tasks.h"
#include "IO.h"

void IRAM_ATTR ISRLeftTurn(void)
{
    uint8_t pinVal = digitalRead(PIN_INPUT_LEFT_TURN);
    switch (pinVal)
    {
    case LOW:
        portENTER_CRITICAL_ISR(&mutex);
        leftBlinkerTaskRunning = true;
        portEXIT_CRITICAL_ISR(&mutex);
        xTaskResumeFromISR(leftBlinkerTaskHandle);
        break;
    case HIGH:
        Serial.println("HIGH");
        portENTER_CRITICAL_ISR(&mutex);
        leftBlinkerTaskRunning = false;
        portEXIT_CRITICAL_ISR(&mutex);
        break;
    }
}

void IRAM_ATTR ISRRightTurn(void)
{
    uint8_t pinVal = digitalRead(PIN_INPUT_RIGHT_TURN);
    switch (pinVal)
    {
    case LOW:
        portENTER_CRITICAL_ISR(&mutex);
        rightBlinkerTaskRunning = true;
        portEXIT_CRITICAL_ISR(&mutex);
        xTaskResumeFromISR(leftBlinkerTaskHandle);
        break;
    case HIGH:
        // vTaskSuspend(leftBlinkerTaskHandle);
        portENTER_CRITICAL_ISR(&mutex);
        rightBlinkerTaskRunning = false;
        portEXIT_CRITICAL_ISR(&mutex);
        break;
    }
}