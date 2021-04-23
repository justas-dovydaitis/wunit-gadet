#include "AngleTask.h"
#include "Bluetooth/Bluetooth.h"
#include "States/State.h"

TaskHandle_t angleTaskHandle = NULL;

void taskUpdateAngleValue(void *param)
{
    String currentAngle;
    for (;;)
    {
        currentAngle = String(pCurrentState->getAngle()->getAngle());
        Serial.println("Angle " + currentAngle);
        Bluetooth::getInstance()->getAngleCharacteristic()->setValue(currentAngle.c_str());
        Bluetooth::getInstance()->getAngleCharacteristic()->notify();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    vTaskDelete(NULL);
}