#include "ControlTask.h"
#include "Controls/Controls.h"

TaskHandle_t controlsTaskHandle = NULL;

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