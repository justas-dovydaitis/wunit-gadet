#include "Bluetooth/Bluetooth.h"
#include "Interrupts/ISRs.h"
#include "IOConfig/IOConfig.h"
#include "RunningState.h"
#include "Tasks/DashboardTask.h"
#include "Tasks/GadgetTask.h"
#include "Tasks/Tasks.h"

void RunningState::onInit()
{
    Serial.println("INIT Running state");
    runTask(taskUpdateDashboard, "UPDATE_DASH", 4096, tskIDLE_PRIORITY, dashboardTaskHandle);
    runTask(taskUpdateGadgets, "UPDATE_GADGETS", 4096, tskIDLE_PRIORITY, gadgetsTaskHandle);
}

void RunningState::onDestroy()
{
    Serial.println("DESTROY Running state");

    vTaskSuspend(dashboardTaskHandle);
    vTaskSuspend(gadgetsTaskHandle);
}