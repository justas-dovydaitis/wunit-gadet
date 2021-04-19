#ifndef __TACH_TASK_H__
#define __TACH_TASK_H__

#include <Arduino.h>

extern TaskHandle_t tachTaskHandle;

void taskUpdateTachValue(void *param);

#endif