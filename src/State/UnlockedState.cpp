#include "UnlockedState.h"
#include "Tasks/Tasks.h"

void UnlockedState::init()
{
    Serial.println("INIT Unlocked state");
    runTask(taskUpdateAngleValue, "UPDATE_ANGLE", 4096, tskIDLE_PRIORITY, angleTaskHandle);
}

void UnlockedState::destroy()
{
    Serial.println("DESTROY Unlocked state");
    vTaskSuspend(angleTaskHandle);
}