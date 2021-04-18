#include "IOConfig.h"
#include "Interrupts/ISRs.h"
#include "Tasks/Tasks.h"

PCF857x ioExpander(0x20, &Wire, true);

void setupIO()
{
    pinMode(PIN_CONTROL_INTERRUPT, INPUT_PULLUP);

    pinMode(PIN_OUTPUT_IGNITION, OUTPUT);
    pinMode(PIN_OUTPUT_STARTER, OUTPUT);
    pinMode(PIN_OUTPUT_LIGHT, OUTPUT);
    pinMode(PIN_OUTPUT_LEFT_TURN, OUTPUT);
    pinMode(PIN_OUTPUT_RIGHT_TURN, OUTPUT);
    pinMode(PIN_OUTPUT_HIGH_BEAM, OUTPUT);
    pinMode(PIN_OUTPUT_HORN, OUTPUT);
    pinMode(PIN_OUTPUT_BRAKE, OUTPUT);
    pinMode(PIN_OUTPUT_AUX1, OUTPUT);
    pinMode(PIN_OUTPUT_AUX2, OUTPUT);
    pinMode(PIN_OUTPUT_AUX3, OUTPUT);
    pinMode(PIN_OUTPUT_AUX4, OUTPUT);
    pinMode(PIN_OUTPUT_AUX5, OUTPUT);
    pinMode(PIN_OUTPUT_AUX6, OUTPUT);
    pinMode(PIN_OUTPUT_AUX7, OUTPUT);
    pinMode(PIN_OUTPUT_AUX8, OUTPUT);

    Wire.begin(21, 22);
    Wire.setClock(100000L);

    ioExpander.begin();
    ioExpander.write16(0);
}
