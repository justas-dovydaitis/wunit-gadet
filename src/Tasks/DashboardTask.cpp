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

    String value = String(angle) + ',' + String(speed) + ',' + String(tach) + ",0";

    Serial.println(value);

    return std::string(value.c_str());
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