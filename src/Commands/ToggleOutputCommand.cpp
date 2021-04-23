#include "ToggleOutputCommand.h"

ToggleOutputCommand::ToggleOutputCommand(uint8_t outputPin, bool isOpenDefault)
    : _outputPin(outputPin), _isOpen(isOpenDefault)
{
    if (_isOpen)
    {
        digitalWrite(_outputPin, HIGH);
    }
}
void ToggleOutputCommand::execute()
{
    _isOpen = !_isOpen;
    if (_isOpen)
    {
        digitalWrite(_outputPin, HIGH);
    }
    else
    {
        digitalWrite(_outputPin, LOW);
    }
}