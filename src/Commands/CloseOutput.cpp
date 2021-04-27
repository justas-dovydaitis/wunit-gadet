#include "CloseOutput.h"
#include "Outputs/Outputs.h"

CloseOutput::CloseOutput(uint8_t outputPin)
    : _outputPin(outputPin)
{
    pinMode(outputPin, OUTPUT);
}
void CloseOutput::execute()
{
    Serial.println("CLOSE OUTPUT");
    Outputs::getInstance()->setPinOff(_outputPin);
}