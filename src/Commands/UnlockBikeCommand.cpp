#include "UnlockBikeCommand.h"
#include "States/UnlockedState.h"

UnlockBikeCommand::UnlockBikeCommand() {}

void UnlockBikeCommand::execute()
{
    setState(new UnlockedState);
}
