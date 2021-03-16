#include "RunningState.h"
#include "Tasks/Tasks.h"

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
    vTaskSuspend(angleTaskHandle);
    vTaskSuspend(speedTaskHandle);
    vTaskSuspend(tachTaskHandle);
    vTaskSuspend(odometerTaskHandle);
}