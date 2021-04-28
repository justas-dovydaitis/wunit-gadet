#include "AnalogSensor/Angle/Angle.h"
#include "AnalogSensor/Speed/Speed.h"
#include "AnalogSensor/Tach/Tach.h"

#include "DashboardTask.h"
#include "States/State.h"

#include <string.h>

TaskHandle_t dashboardTaskHandle = NULL;

std::string makeDashboardString()
{
    int16_t angle = Angle::getInstance()->getValue();
    uint16_t speed = Speed::getInstance()->getValue();
    uint16_t tach = Tach::getInstance()->getValue();

    char buff[28];
    sprintf(buff, "%d,%i,%i,%d", angle, speed, tach, 0);

    return std::string(buff);
}

void taskUpdateDashboard(void *param)
{
    std::string value;
    for (;;)
    {
        value = makeDashboardString();
        Bluetooth::getInstance()->getDashboardCharacteristic()->setValue(value);
        Bluetooth::getInstance()->getDashboardCharacteristic()->notify();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}