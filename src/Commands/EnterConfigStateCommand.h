#ifndef __EXIT_CONFIG_STATE_COMMAND_H__
#define __EXIT_CONFIG_STATE_COMMAND_H__

#include "Command.h"

class EnterConfigStateCommand : public Command
{
    explicit EnterConfigStateCommand();
    void execute() override;
};

#endif