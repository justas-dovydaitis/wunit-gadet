#ifndef __ENTER_CONFIG_STATE_COMMAND_H__
#define __ENTER_CONFIG_STATE_COMMAND_H__

#include "Command.h"

class EnterConfigStateCommand : public Command
{
public:
    explicit EnterConfigStateCommand();
    void execute() override;
};

#endif