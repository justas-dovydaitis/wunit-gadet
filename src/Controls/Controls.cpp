#include "Controls.h"

#define INCLUDE_xTaskResumeFromISR 1

Button::Button(TaskFunction_t assignedTask) : _assignedTask(assignedTask)
{
    if (!_taskHandle)
    {
        TaskHandle_t handle;
        xTaskCreate(_assignedTask, "", 2048, nullptr, tskIDLE_PRIORITY, &handle);
        vTaskSuspend(handle);
        _taskHandle = handle;
    }
}

MomentaryButton::MomentaryButton(TaskFunction_t assignedTask) : Button(assignedTask) {}

void MomentaryButton::switchOn()
{
    xTaskResumeFromISR(_taskHandle);
}

void MomentaryButton::switchOff()
{
    vTaskSuspend(_taskHandle);
}

LatchingButton::LatchingButton(TaskFunction_t assignedTask) : Button(assignedTask) {}

void LatchingButton::switchOn()
{
    BaseType_t xYieldRequired;
    Serial.println("SWITCH ON ENTER" + (int)LatchingButton::_taskHandle);
    if (_taskHandle)
    {
        Serial.println("TASK RESUME" + (int)_taskHandle);


        xYieldRequired = xTaskResumeFromISR(_taskHandle);
        _status = true;
        if (xYieldRequired == pdTRUE)
        {
            portYIELD_FROM_ISR();
        }
    }
    Serial.println("SWITCH ON EXIT");
}

void LatchingButton::switchOff()
{
    Serial.println("SWITCH OFF ENTER");
    if (_taskHandle)
    {
        Serial.println("TASK Suspend");
        xTaskResumeFromISR(_taskHandle);
        _status = true;
    }
    Serial.println("SWITCH OFF EXIT");
}