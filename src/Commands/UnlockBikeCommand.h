#ifndef __UNLOCK_BIKE_COMMAND_H__
#define __UNLOCK_BIKE_COMMAND_H__

#include "Command.h"

class UnlockBikeCommand : public Command
{
public:
    explicit UnlockBikeCommand();
    void execute() override;
};

#endif