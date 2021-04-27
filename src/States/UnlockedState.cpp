#include "Bluetooth/Bluetooth.h"
#include "Interrupts/ISRs.h"
#include "IOConfig/IOConfig.h"
#include "Tasks/Tasks.h"
#include "Tasks/ControlTask.h"
#include "UnlockedState.h"

void UnlockedState::init()
{
    saveState();
    Serial.println("INIT: Unlocked state");
    runTask(taskControls, "CONTROLS", 4096, 1, controlsTaskHandle);
}

void UnlockedState::destroy()
{
    Serial.println("DESTROY: Unlocked state");

    vTaskSuspend(controlsTaskHandle);
}
