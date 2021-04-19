#ifndef __CLOSE_OUTPUT_COMMAND_H__
#define __CLOSE_OUTPUT_COMMAND_H__
#include "Command.h"
class OpenOutputCommand : public Command
{
private:
    uint8_t _outputPin;

public:
    explicit OpenOutputCommand(uint8_t outputPin);
    void execute() const override;
};

#endif