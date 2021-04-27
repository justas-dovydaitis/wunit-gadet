#include "Constants.h"
#include "IOConfig.h"
#include "Interrupts/ISRs.h"
#include "Tasks/Tasks.h"
#include "Outputs/Outputs.h"

PCF857x ioExpander(0x20, &Wire, true);

// OutputPin_t outputs[14] = {4, 5, 15, 19, 18, 23, 25, 26, 27, 32, 33, 0, 13, 14};

void setupIO()
{
    Outputs::getInstance();
    pinMode(PIN_CONTROL_INTERRUPT, INPUT_PULLUP);

    // for (int i = 0; i < C_OUTPUT_COUNT; i++)
    // {
    //     pinMode(outputs[i], OUTPUT);
    // }

    Wire.begin(21, 22);
    Wire.setClock(100000L);

    ioExpander.begin();
    ioExpander.write16(0);
}
