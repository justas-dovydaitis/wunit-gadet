#ifndef __CONTROL_TASKS_H__
#define __CONTROL_TASKS_H__

#include <Arduino.h>
#include "Controls/Controls.h"
#include "IOConfig/IOConfig.h"

extern TaskHandle_t controlsTaskHandle;
extern ulong controlLastTriggered;

void taskControls(void *param);

#endif
