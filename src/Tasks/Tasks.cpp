#include "Tasks.h"
#include "Angle/Angle.h"
#include "Bluetooth/Bluetooth.h"

TaskHandle_t angleTaskHandle = NULL;
TaskHandle_t speedTaskHandle = NULL;
TaskHandle_t tachTaskHandle = NULL;
TaskHandle_t odometerTaskHandle = NULL;

void taskUpdateAngleValue(void *param)
{
    String currentAngle;
    while (1)
    {
        currentAngle = String(getCurrentAngle());
        pAngleCharacteristic->setValue(currentAngle.c_str());
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    vTaskDelete(NULL);
}

void taskUpdateSpeedValue(void *param)
{

    uint minSpeed = 0;
    uint maxSpeed = 299;
    uint currentVal;
    while (1)
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
    while (1)
    {
        currentVal = random(minTach, maxTach);

        pTachometerCharacteristic->setValue(String(currentVal).c_str());
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    vTaskDelete(NULL);
}
void taskUpdateOdometerValue(void *param)
{
    double currentVal = 15523.6;
    while (1)
    {
        currentVal += 0.1;
        pOdometerCharacteristic->setValue(String(currentVal).c_str());

        vTaskDelay(pdMS_TO_TICKS(7000));
    }
    vTaskDelete(NULL);
}
