#include "Tasks.h"
#include "Angle/Angle.h"
#include "Bluetooth/Bluetooth.h"

#include "IO.h"

portMUX_TYPE mutex = portMUX_INITIALIZER_UNLOCKED;

TaskHandle_t angleTaskHandle = NULL;
TaskHandle_t speedTaskHandle = NULL;
TaskHandle_t tachTaskHandle = NULL;
TaskHandle_t odometerTaskHandle = NULL;
TaskHandle_t leftBlinkerTaskHandle = NULL;
bool leftBlinkerTaskRunning = false;
TaskHandle_t rightBlinkerTaskHandle = NULL;
bool rightBlinkerTaskRunning = false;

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

void taskLeftBlinker(void *param)
{

    Serial.println("TSK LEFT BLINKER CREATED");
    vTaskSuspend(NULL);

    for (;;)
    {
        Serial.println("BLINK");
        portENTER_CRITICAL(&mutex);
        ioExpander.toggle(PIN_OUTPUT_LEFT_TURN);
        portEXIT_CRITICAL(&mutex);
        vTaskDelay(pdMS_TO_TICKS(666));
        if (!leftBlinkerTaskRunning)
        {
            portENTER_CRITICAL(&mutex);
            ioExpander.write(PIN_OUTPUT_LEFT_TURN, HIGH);
            portEXIT_CRITICAL(&mutex);

            vTaskSuspend(NULL);
        }
    }
}
void taskRightBlinker(void *param)
{
    Serial.println("TSK RIGH BLINKER CREATED");
    vTaskSuspend(NULL);

    for (;;)
    {
        Serial.println("BLINK");
        portENTER_CRITICAL(&mutex);
        ioExpander.toggle(PIN_OUTPUT_RIGHT_TURN);
        portEXIT_CRITICAL(&mutex);
        vTaskDelay(pdMS_TO_TICKS(666));
        if (!leftBlinkerTaskRunning)
        {
            ioExpander.write(PIN_OUTPUT_RIGHT_TURN, HIGH);
            vTaskSuspend(NULL);
        }
    }
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
void initializeTasks()
{
    xTaskCreate(taskLeftBlinker, "LEFT BLINKER", 2084, nullptr, tskIDLE_PRIORITY, &leftBlinkerTaskHandle);
    xTaskCreate(taskRightBlinker, "RIGHT BLINKER", 2048, nullptr, tskIDLE_PRIORITY, &rightBlinkerTaskHandle);
}