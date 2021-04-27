#include "CloseOutputCommand.h"

CloseOutputCommand::CloseOutputCommand(uint8_t outputPin)
    : _outputPin(outputPin)
{
    pinMode(outputPin, OUTPUT);
}
void CloseOutputCommand::execute()
{
    Serial.println("CLOSE OUTPUT");
    digitalWrite(_outputPin, LOW);
}