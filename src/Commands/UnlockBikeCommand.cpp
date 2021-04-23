#include "UnlockBikeCommand.h"
#include "States/UnlockedState.h"

void UnlockBikeCommand::execute()
{
    setState(new UnlockedState);
}
