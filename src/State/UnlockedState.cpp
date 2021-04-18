#include "Interrupts/ISRs.h"
#include "IOConfig/IOConfig.h"
#include "Tasks/Tasks.h"
#include "UnlockedState.h"

void UnlockedState::init()
{
    Serial.println("INIT: Unlocked state");

    runTask(taskUpdateAngleValue, "UPDATE_ANGLE", 4096, tskIDLE_PRIORITY, angleTaskHandle);
    // runTask(taskLight, "LIGHT", 2048, tskIDLE_PRIORITY, lightTaskHandle);
    // runTask(taskHighBeam, "HIGH_BEAM", 2048, tskIDLE_PRIORITY, highBeamTaskHandle);
    // runTask(taskHorn, "HORN", 2048, tskIDLE_PRIORITY, hornTaskHandle);
    // runTask(taskLeftTurn, "LEFT TURN", 2048, tskIDLE_PRIORITY, leftTurnTaskHandle);
    // runTask(taskRightTurn, "RIGHT TURN", 2048, tskIDLE_PRIORITY, rightTurnTaskHandle);
    // runTask(taskBrake, "BRAKE", 2048, tskIDLE_PRIORITY, brakeTaskHandle);
    // horn = SimpleGadget(PIN_INPUT_0, PIN_OUTPUT_HORN, TOGGLE_WHILE_PRESSED);
    // attachInterrupt(digitalPinToInterrupt(PIN_CONTROL_INTERRUPT), ISRAlarm, CHANGE);
}

void UnlockedState::destroy()
{
    Serial.println("DESTROY: Unlocked state");

    // detachInterrupt(PIN_CONTROL_INTERRUPT);

    vTaskSuspend(angleTaskHandle);

    // vTaskSuspend(lightTaskHandle);
    // vTaskSuspend(highBeamTaskHandle);
    // vTaskSuspend(hornTaskHandle);
    // vTaskSuspend(leftTurnTaskHandle);
    // vTaskSuspend(rightTurnTaskHandle);
    // vTaskSuspend(brakeTaskHandle);
}
