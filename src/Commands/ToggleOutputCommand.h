#ifndef __TOGGLE_OUTPUT_COMMAND__
#define __TOGGLE_OUTPUT_COMMAND__

#include "Command.h"

class ToggleOutputCommand : public Command
{
private:
    uint8_t _outputPin;
    bool _isOpen = false;

public:
    explicit ToggleOutputCommand(uint8_t outputPin, bool isOpenDefault = false);
    void execute();
};

#endif