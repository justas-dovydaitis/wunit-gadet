#ifndef __UNLOCK_BIKE_H__
#define __UNLOCK_BIKE_H__

#include "Command.h"

class UnlockBike : public CommandInterface
{
public:
    explicit UnlockBike();
    void execute() override;
};

#endif