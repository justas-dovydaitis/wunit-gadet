#ifndef __CLOSE_OUTPUT_COMMAND_H__
#define __CLOSE_OUTPUT_COMMAND_H__
#include "Command.h"

class CloseOutputCommand : public Command
{
private:
    uint8_t _outputPin;

public:
    explicit CloseOutputCommand(uint8_t outputPin);
    void execute() override;
};

#endif