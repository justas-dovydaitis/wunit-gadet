#include "AnalogSensor/Angle/Angle.h"
#include "Config/Config.h"
#include "CrashDetectionTask.h"
#include "States/State.h"
#include "States/CrashedState.h"

TaskHandle_t crashDetectionTaskHandle = NULL;

void taskCrashDetection(void *param)
{
    Angle *pAngle = Angle::getInstance();
    uint16_t angleBoundary = Config::getInstance()->getLeanAngleBoundary();
    for (;;)
    {
        if (abs(pAngle->getValue()) > angleBoundary)
        {
            setState(new CrashedState);
        }

        vTaskDelay(pdMS_TO_TICKS(30));
    }
}