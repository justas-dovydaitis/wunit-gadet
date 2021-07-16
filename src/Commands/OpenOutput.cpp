#include "OpenOutput.h"
#include "Outputs/Outputs.h"

OpenOutput::OpenOutput(uint8_t outputPin)
    : _outputPin(outputPin)
{
}
void OpenOutput::execute()
{
    Serial.println("OPEN OUTPUT");

    Outputs::getInstance()->setPinOn(_outputPin);
}
