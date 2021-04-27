#ifndef __TOGGLE_OUTPUT__
#define __TOGGLE_OUTPUT__

#include "Command.h"

class ToggleOutput : public Command
{
private:
    uint8_t _outputPin;
    bool _isOpen = false;

public:
    explicit ToggleOutput(std::string param);
    explicit ToggleOutput(uint8_t outputPin, bool isOpenDefault = false);
    void execute();
};

#endif