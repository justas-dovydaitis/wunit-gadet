#include "CloseOutputCommand.h"
#include "Outputs/Outputs.h"

CloseOutputCommand::CloseOutputCommand(uint8_t outputPin)
    : _outputPin(outputPin)
{
    pinMode(outputPin, OUTPUT);
}
void CloseOutputCommand::execute()
{
    Serial.println("CLOSE OUTPUT");
    Outputs::getInstance()->setPinOff(_outputPin);
}