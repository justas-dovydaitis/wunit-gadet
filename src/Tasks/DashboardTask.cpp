#include "Controls/Controls.h"
#include "DashboardTask.h"
#include "States/State.h"

TaskHandle_t dashboardTaskHandle = NULL;

std::string makeDashboardString()
{
    //     uint8_t angle = pAngle
    //     uint16_t speed = ()->getSpeed();
}

void taskUpdateDashboard(void *param)
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