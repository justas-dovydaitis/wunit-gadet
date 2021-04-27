#ifndef __ENTER_CONFIG_STATE_H__
#define __ENTER_CONFIG_STATE_H__

#include "Command.h"

class EnterConfigState : public Command
{
public:
    explicit EnterConfigState();
    void execute() override;
};

#endif