#ifndef __ALARM_TASK_H__
#define __ALARM_TASK_H__

#include <Arduino.h>

#define DEFAULT_ALARM_DURATION 10000

extern TaskHandle_t alarmTaskHandle;
extern ulong alarmLastTriggered;

void taskAlarm(void *param);

#endif
