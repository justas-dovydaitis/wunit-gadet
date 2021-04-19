#include "OpenOutputCommand.h"

OpenOutputCommand::OpenOutputCommand(uint8_t outputPin)
    : _outputPin(outputPin)
{
    pinMode(outputPin, OUTPUT);
}
void OpenOutputCommand::execute() const
{
        Serial.println("OPEN OUTPUT");
    digitalWrite(_outputPin, HIGH);
}
