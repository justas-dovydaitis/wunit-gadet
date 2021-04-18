#include "AlarmTask.h"

TaskHandle_t alarmTaskHandle = NULL;
ulong alarmLastTriggered = 0;

ulong alarmDuration = DEFAULT_ALARM_DURATION;

void taskAlarm(void *param)
{
    ulong currentTime = millis();
    for (;;)
    {
        currentTime = millis();
        if (currentTime - alarmLastTriggered < alarmDuration)
        {
            Serial.println("ALARM!");
        }
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}