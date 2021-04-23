#include <Arduino.h>

#include "Angle/Angle.h"
#include "Bluetooth/Bluetooth.h"
#include "Commands/CloseOutputCommand.h"
#include "Commands/LockBikeCommand.h"
#include "Commands/OpenOutputCommand.h"
#include "Commands/ToggleOutputCommand.h"
#include "Config/Config.h"
#include "States/InitState.h"
#include "IOConfig/IOConfig.h"
#include "Tasks/Tasks.h"

void setup()
{
  Serial.begin(115200);
  setupIO();
  setState(new InitState);

  // controls[0].attachPress(new OpenOutputCommand(PIN_OUTPUT_IGNITION));
  // controls[0].attachDoublePress(new CloseOutputCommand(PIN_OUTPUT_IGNITION));
  // controls[0].attachLongPressStart(new ToggleOutputCommand(PIN_OUTPUT_STARTER));
  // controls[0].attachDuringLongPress(During);
  // controls[0].attachLongPressStart(WhileStart);
  // controls[0].attachLongPressStop(WhileStop);

  vTaskDelete(NULL);
}
void loop()
{
}
