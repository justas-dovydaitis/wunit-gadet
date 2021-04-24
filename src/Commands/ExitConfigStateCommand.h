#ifndef __EXIT_CONFIG_STATE_COMMAND_H__
#define __EXIT_CONFIG_STATE_COMMAND_H__

#include "Command.h"

class ExitConfigStateCommand : public Command
{
public:
    explicit ExitConfigStateCommand();
    void execute() override;
};

#endif