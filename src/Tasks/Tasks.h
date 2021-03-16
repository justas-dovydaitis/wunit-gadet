#ifndef __TASKS_H__
#define __TASKS_H__

#include <Arduino.h>

extern TaskHandle_t angleTaskHandle;
extern TaskHandle_t speedTaskHandle;
extern TaskHandle_t tachTaskHandle;
extern TaskHandle_t odometerTaskHandle;

extern void taskUpdateAngleValue(void *param);

extern void taskUpdateSpeedValue(void *param);

extern void taskUpdateTachValue(void *param);

extern void taskUpdateOdometerValue(void *param);

extern void runTask(TaskFunction_t taskCode, const char *taskName, int stackSize, UBaseType_t priority, TaskHandle_t &handle);

#endif