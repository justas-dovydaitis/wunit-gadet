#include "TachTask.h"
#include "Bluetooth/Bluetooth.h"

TaskHandle_t tachTaskHandle = NULL;


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