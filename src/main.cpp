#include <Arduino.h>

#include "Angle/Angle.h"
#include "Bluetooth/Bluetooth.h"

#include "Tasks/Tasks.h"

void setup()
{
  Serial.begin(115200);
  setupBLE();
  setupAngle();

  xTaskCreate(taskUpdateAngleValue,
              "UPDATE_ANGLE",
              4096,
              nullptr,
              tskIDLE_PRIORITY,
              &angleTaskHandle);
  xTaskCreate(taskUpdateTachValue,
              "UPDATE_TACH",
              4096,
              nullptr,
              tskIDLE_PRIORITY,
              &angleTaskHandle);
  xTaskCreate(taskUpdateSpeedValue,
              "UPDATE_SPEED",
              4096,
              nullptr,
              tskIDLE_PRIORITY,
              &angleTaskHandle);
  xTaskCreate(taskUpdateOdometerValue,
              "UPDATE_ODOMETER",
              4096,
              nullptr,
              tskIDLE_PRIORITY,
              &angleTaskHandle);
}
void loop()
{
}
