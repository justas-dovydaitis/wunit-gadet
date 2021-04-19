#include "SpeedTask.h"
#include "Bluetooth/Bluetooth.h"

TaskHandle_t speedTaskHandle = NULL;

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