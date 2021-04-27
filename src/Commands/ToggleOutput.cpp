#include "ToggleOutput.h"
#include "Outputs/Outputs.h"

ToggleOutput::ToggleOutput(std::string param)
{
    uint8_t splitter = param.find(',');
    _isOpen = atoi(param.substr(splitter + 1).c_str());
    _outputPin = atoi(param.substr(0, splitter - 1).c_str());
}

ToggleOutput::ToggleOutput(uint8_t outputPin, bool isOpenDefault)
    : _outputPin(outputPin), _isOpen(isOpenDefault)
{
    if (_isOpen)
    {
        Outputs::getInstance()->setPinOff(outputPin);
    }
}
void ToggleOutput::execute()
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