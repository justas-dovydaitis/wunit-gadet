#include "Tasks.h"
#include "Angle/Angle.h"
#include "Bluetooth/Bluetooth.h"
#include "IOConfig/IOConfig.h"

TaskHandle_t angleTaskHandle = NULL;
TaskHandle_t speedTaskHandle = NULL;
TaskHandle_t tachTaskHandle = NULL;
TaskHandle_t odometerTaskHandle = NULL;

void taskUpdateAngleValue(void *param)
{
    String currentAngle;
    for (;;)
    {
        currentAngle = String(getCurrentAngle());
        Serial.println("Angle " + currentAngle);
        pAngleCharacteristic->setValue(currentAngle.c_str());
        pAngleCharacteristic->notify();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    vTaskDelete(NULL);
}

void taskUpdateSpeedValue(void *param)
{

    uint minSpeed = 0;
    uint maxSpeed = 299;
    uint currentVal;
    for (;;)
    {
        currentVal = random(minSpeed, maxSpeed);

        pSpeedometerCharacteristic->setValue(String(currentVal).c_str());
        pSpeedometerCharacteristic->notify();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    vTaskDelete(NULL);
}
void taskUpdateTachValue(void *param)
{
    uint minTach = 800;
    uint maxTach = 14000;
    uint currentVal;
    for (;;)
    {
        currentVal = random(minTach, maxTach);

        pTachometerCharacteristic->setValue(String(currentVal).c_str());
        pTachometerCharacteristic->notify();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    vTaskDelete(NULL);
}
void taskUpdateOdometerValue(void *param)
{
    double currentVal = 15523.6;
    for (;;)
    {
        currentVal += 0.1;
        pOdometerCharacteristic->setValue(String(currentVal).c_str());
        pOdometerCharacteristic->notify();
        vTaskDelay(pdMS_TO_TICKS(7000));
    }
    vTaskDelete(NULL);
}

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