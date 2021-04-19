#include "OpenOutputCommand.h"

OpenOutputCommand::OpenOutputCommand(uint8_t outputPin)
    : _outputPin(outputPin)
{
    pinMode(outputPin, OUTPUT);
}
void OpenOutputCommand::execute() const
{
    digitalWrite(_outputPin, HIGH);
}
