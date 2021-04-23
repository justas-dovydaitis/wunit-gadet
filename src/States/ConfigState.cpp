#include "Bluetooth/Bluetooth.h"
#include "ConfigState.h"

void ConfigState::init()
{
    pControlService->start();
    pDashboardService->stop();
    pConfigService->start();
    saveState();
}
void ConfigState::destroy()
{
    pConfigService->stop();
}