#include "ExitConfigStateCommand.h"
#include "States/State.h"
#include "States/UnlockedState.h"


ExitConfigStateCommand::ExitConfigStateCommand() {}

void ExitConfigStateCommand::execute()
{
    setState(new UnlockedState);
}