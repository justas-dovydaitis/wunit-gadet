#ifndef __LOCK_BIKE_H__
#define __LOCK_BIKE_H__

#include "Command.h"

class LockBike : public CommandInterface
{
public:
    explicit LockBike();
    void execute() override;
};

#endif