#include "Bluetooth/Bluetooth.h"
#include "Interrupts/ISRs.h"
#include "IOConfig/IOConfig.h"
#include "Tasks/ControlTask.h"
#include "Tasks/DashboardTask.h"
#include "Tasks/GadgetTask.h"
#include "Tasks/Tasks.h"
#include "UnlockedState.h"

void UnlockedState::init()
{
    saveState();
    Serial.println("INIT: Unlocked state");
    runTask(taskControls, "CONTROLS", 4096, 1, controlsTaskHandle);
    runTask(taskUpdateDashboard, "Dash", 4096, 1, dashboardTaskHandle);
    runTask(taskUpdateGadgets, "gadget", 4096, 1, gadgetsTaskHandle);
}

void UnlockedState::destroy()
{
    Serial.println("DESTROY: Unlocked state");

    vTaskSuspend(controlsTaskHandle);
    vTaskSuspend(dashboardTaskHandle);
    vTaskSuspend(gadgetsTaskHandle);
}
