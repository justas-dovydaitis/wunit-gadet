#include "Bluetooth/Bluetooth.h"
#include "IgnitionState.h"
#include "Interrupts/ISRs.h"
#include "IOConfig/IOConfig.h"

void IgnitionState::init()
{
    saveState();
}

void IgnitionState::destroy()
{
}