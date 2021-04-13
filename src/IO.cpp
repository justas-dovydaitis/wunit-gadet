#include "IO.h"
#include "Interrupts/ISRs.h"
#include "Tasks/Tasks.h"

PCF857x ioExpander(0x20, &Wire, true);

void setupIO()
{
    pinMode(PIN_INPUT_LOCK, INPUT);
    pinMode(PIN_INPUT_LIGHT, INPUT);
    pinMode(PIN_INPUT_LEFT_TURN, INPUT_PULLUP);
    pinMode(PIN_INPUT_RIGHT_TURN, INPUT_PULLUP);
    pinMode(PIN_INPUT_KILL, INPUT);
    pinMode(PIN_INPUT_HIGH_BEAM, INPUT);
    pinMode(PIN_INPUT_STARTER, INPUT);
    pinMode(PIN_INPUT_HORN, INPUT);
    pinMode(PIN_INPUT_BRAKE, INPUT);
    pinMode(PIN_INPUT_STAND, INPUT);

    pinMode(PIN_IO_EXPANDER_INTERRUPT, INPUT_PULLUP);

    Wire.begin(21, 22);
    Wire.setClock(100000L);

    ioExpander.begin();

    attachInterrupt(digitalPinToInterrupt(PIN_INPUT_LEFT_TURN), ISRLeftTurn, CHANGE);
    attachInterrupt(digitalPinToInterrupt(PIN_INPUT_RIGHT_TURN), ISRRightTurn, CHANGE);
}
