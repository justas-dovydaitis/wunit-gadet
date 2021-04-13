#ifndef __TASKS_H__
#define __TASKS_H__

#include <Arduino.h>

extern portMUX_TYPE mutex;

extern TaskHandle_t angleTaskHandle;
extern TaskHandle_t speedTaskHandle;
extern TaskHandle_t tachTaskHandle;
extern TaskHandle_t odometerTaskHandle;

extern TaskHandle_t leftBlinkerTaskHandle;
extern bool leftBlinkerTaskRunning;
extern TaskHandle_t rightBlinkerTaskHandle;
extern bool rightBlinkerTaskRunning;

extern void taskUpdateAngleValue(void *param);

extern void taskUpdateSpeedValue(void *param);

extern void taskUpdateTachValue(void *param);

extern void taskUpdateOdometerValue(void *param);

extern void taskLeftBlinker(void *param);

extern void taskRightBlinker(void *param);

extern void runTask(TaskFunction_t taskCode, const char *taskName, int stackSize, UBaseType_t priority, TaskHandle_t &handle);

extern void initializeTasks();

#endif