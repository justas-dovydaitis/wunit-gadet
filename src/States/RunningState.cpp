#include "RunningState.h"
#include "Interrupts/ISRs.h"
#include "IOConfig/IOConfig.h"
#include "Tasks/AngleTask.h"
#include "Tasks/OdometerTask.h"
#include "Tasks/SpeedTask.h"
#include "Tasks/TachTask.h"
#include "Tasks/Tasks.h"

TaskHandle_t blinkHandle;
void RunningState::blink(void *param)
{
    Serial.println("Blink");
    vTaskDelay(pdMS_TO_TICKS(1000));
}

void RunningState::init()
{
    Serial.println("INIT Running state");
    runTask(taskUpdateAngleValue, "UPDATE_ANGLE", 4096, tskIDLE_PRIORITY, angleTaskHandle);
    runTask(taskUpdateSpeedValue, "UPDATE_SPEED", 4096, tskIDLE_PRIORITY, speedTaskHandle);
    runTask(taskUpdateTachValue, "UPDATE_TACH", 4096, tskIDLE_PRIORITY, tachTaskHandle);
    runTask(taskUpdateOdometerValue, "UPDATE_ODOMETER", 4096, tskIDLE_PRIORITY, odometerTaskHandle);
}

void RunningState::destroy()
{

    Serial.println("DESTROY Running state");

    // detachInterrupt(digitalPinToInterrupt(PIN_INPUT_LOCK));
    // detachInterrupt(digitalPinToInterrupt(PIN_INPUT_LIGHT));
    // detachInterrupt(digitalPinToInterrupt(PIN_INPUT_LEFT_TURN));
    // detachInterrupt(digitalPinToInterrupt(PIN_INPUT_RIGHT_TURN));
    // detachInterrupt(digitalPinToInterrupt(PIN_INPUT_KILL));
    // detachInterrupt(digitalPinToInterrupt(PIN_INPUT_HIGH_BEAM));

    vTaskSuspend(angleTaskHandle);
    vTaskSuspend(speedTaskHandle);
    vTaskSuspend(tachTaskHandle);
    vTaskSuspend(odometerTaskHandle);
}