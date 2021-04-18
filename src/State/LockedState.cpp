#include "LockedState.h"
#include "Interrupts/ISRs.h"
#include "IOConfig/IOConfig.h"
#include "Tasks/Tasks.h"
#include "Tasks/AlarmTask.h"

void LockedState::init()
{
    Serial.println("INIT: Locked state");
    runTask(taskAlarm, "ALARM", 4096, tskIDLE_PRIORITY, alarmTaskHandle);

    attachInterrupt(digitalPinToInterrupt(PIN_CONTROL_INTERRUPT), ISRAlarm, CHANGE);
}

void LockedState::destroy()
{
    Serial.println("DESTROY: Locked state");

    detachInterrupt(PIN_CONTROL_INTERRUPT);

    vTaskSuspend(alarmTaskHandle);
}