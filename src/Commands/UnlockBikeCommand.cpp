#include "UnlockBikeCommand.h"
#include "States/UnlockedState.h"

void UnlockBikeCommand::execute() const
{
    setState(new UnlockedState);
}
