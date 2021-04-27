#ifndef __GADGET_TASK_H__
#define __GADGET_TASK_H__

#include <Arduino.h>

extern TaskHandle_t gadgetsTaskHandle;

void taskUpdateGadgets(void *param);

#endif