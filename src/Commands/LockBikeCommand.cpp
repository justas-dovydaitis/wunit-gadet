#include "LockBikeCommand.h"
#include "States/LockedState.h"

void LockBikeCommand::execute() const
{
    setState(new LockedState);
}
