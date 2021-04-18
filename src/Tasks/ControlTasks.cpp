#include "ControlTasks.h"
#include "IOConfig/IOConfig.h"

TaskHandle_t controlsTaskHandle = NULL;
portMUX_TYPE IICMutex = portMUX_INITIALIZER_UNLOCKED;

bool controlTriggered = false;
ulong controlLastTriggered = 0;

void taskControls(void *param)
{
    for (;;)
    {
        for (uint16_t i = 0; i < 1; i++)
        {
            controls[i].check();
        }
        vTaskDelay(pdMS_TO_TICKS(30));
    }
}