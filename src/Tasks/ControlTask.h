#ifndef __CONTROL_TASKS_H__
#define __CONTROL_TASKS_H__

#include <Arduino.h>

extern TaskHandle_t controlsTaskHandle;

void taskControls(void *param);

#endif
