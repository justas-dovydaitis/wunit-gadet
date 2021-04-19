#ifndef __LOCK_BIKE_COMMAND_H__
#define __LOCK_BIKE_COMMAND_H__

#include "Command.h"


class LockBikeCommand : public Command
{
public:
    explicit LockBikeCommand();
    void execute() const override;
};

#endif