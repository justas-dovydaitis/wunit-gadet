#ifndef __EXIT_CONFIG_STATE_H__
#define __EXIT_CONFIG_STATE_H__

#include "Command.h"

class ExitConfigState : public CommandInterface
{
public:
    explicit ExitConfigState();
    void execute() override;
};

#endif