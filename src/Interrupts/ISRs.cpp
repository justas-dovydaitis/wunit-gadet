#include "ISRs.h"

#include "Tasks/AlarmTask.h"

void IRAM_ATTR ISRAlarm()
{
    alarmLastTriggered = millis();
}