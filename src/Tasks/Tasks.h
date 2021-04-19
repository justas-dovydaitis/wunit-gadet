#ifndef __TASKS_H__
#define __TASKS_H__

#include <Arduino.h>

void runTask(TaskFunction_t taskCode, const char *taskName, int stackSize, UBaseType_t priority, TaskHandle_t &handle);

#endif