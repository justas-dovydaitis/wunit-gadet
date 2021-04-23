#include "OdometerTask.h"
#include "Bluetooth/Bluetooth.h"

TaskHandle_t odometerTaskHandle = NULL;

void taskUpdateOdometerValue(void *param)
{
    double currentVal = 15523.6;
    for (;;)
    {
        currentVal += 0.1;
        Bluetooth::getInstance()->getOdometerCharacteristic()->setValue(String(currentVal).c_str());
        Bluetooth::getInstance()->getOdometerCharacteristic()->notify();
        vTaskDelay(pdMS_TO_TICKS(7000));
    }
    vTaskDelete(NULL);
}
