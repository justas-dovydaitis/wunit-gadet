
#ifndef __SPEED_TASK_H__
#define __SPEED_TASK_H__

#include <Arduino.h>

extern TaskHandle_t speedTaskHandle;

void taskUpdateSpeedValue(void *param);

#endif
