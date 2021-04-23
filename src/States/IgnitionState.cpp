#include "Bluetooth/Bluetooth.h"
#include "IgnitionState.h"
#include "Interrupts/ISRs.h"
#include "IOConfig/IOConfig.h"

void IgnitionState::init()
{
    saveState();
    _pBluetooth->getControlService()->start();
    _pBluetooth->getDashboardService()->start();
}

void IgnitionState::destroy()
{
}