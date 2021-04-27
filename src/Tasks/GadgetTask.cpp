#include "Bluetooth/Bluetooth.h"
#include "GadgetTask.h"
#include "Outputs/Outputs.h"

TaskHandle_t gadgetsTaskHandle = nullptr;

void taskUpdateGadgets(void *param)
{
    uint16_t value;
    for (;;)
    {
        value = Outputs::getInstance()->getOutputStatusBitmask();
        Bluetooth::getInstance()->getGadgetCharacteristic()->setValue(value);
        Bluetooth::getInstance()->getGadgetCharacteristic()->notify();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    vTaskDelete(NULL);
}
