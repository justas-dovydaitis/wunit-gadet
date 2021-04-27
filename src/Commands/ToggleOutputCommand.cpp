#include "ToggleOutputCommand.h"
#include "Outputs/Outputs.h"

ToggleOutputCommand::ToggleOutputCommand(std::string param)
{
    uint8_t splitter = param.find(',');
    _isOpen = atoi(param.substr(splitter + 1).c_str());
    _outputPin = atoi(param.substr(0, splitter - 1).c_str());
}

ToggleOutputCommand::ToggleOutputCommand(uint8_t outputPin, bool isOpenDefault)
    : _outputPin(outputPin), _isOpen(isOpenDefault)
{
    if (_isOpen)
    {
        Outputs::getInstance()->setPinOff(outputPin);
    }
}
void ToggleOutputCommand::execute()
{
    _isOpen = !_isOpen;
    if (_isOpen)
    {
        Outputs::getInstance()->setPinOn(_outputPin);
    }
    else
    {
        Outputs::getInstance()->setPinOff(_outputPin);
    }
}