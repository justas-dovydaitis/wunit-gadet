#include "Tasks.h"

void runTask(TaskFunction_t taskCode, const char *taskName, int stackSize, UBaseType_t priority, TaskHandle_t &handle)
{
    Serial.println("RUN TASK" + String(taskName));
    if (handle != NULL)
    {
        Serial.println("RESUMING TASK");
        vTaskResume(handle);
    }
    else
    {
        Serial.println("CREATING NEW TASK");
        xTaskCreate(taskCode, taskName, stackSize, nullptr, priority, &handle);
    }
}