#include "ISRs.h"

#include "State/State.h"
#include "Tasks/AlarmTask.h"

void IRAM_ATTR ISRAlarm()
{
    alarmLastTriggered = millis();
}