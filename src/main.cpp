#include <Arduino.h>

#include "Angle/Angle.h"
#include "Bluetooth/Bluetooth.h"
#include "Commands/CloseOutputCommand.h"
#include "Commands/LockBikeCommand.h"
#include "Commands/OpenOutputCommand.h"
#include "States/LockedState.h"
#include "IOConfig/IOConfig.h"
#include "Tasks/Tasks.h"

void setup()
{
  Serial.begin(115200);
  setupIO();
  setupBLE();
  setupAngle();
  setState(new LockedState);

  controls[0].attachPress(new OpenOutputCommand(PIN_OUTPUT_HORN));
  controls[0].attachDoublePress(new CloseOutputCommand(PIN_OUTPUT_HORN));
  controls[0].attachLongPressStop(new LockBikeCommand);
  // controls[0].attachDuringLongPress(During);
  // controls[0].attachLongPressStart(WhileStart);
  // controls[0].attachLongPressStop(WhileStop);

  vTaskDelete(NULL);
}
void loop()
{
}
