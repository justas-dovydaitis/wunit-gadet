#include "EnterConfigStateCommand.h"
#include "States/ConfigState.h"
#include "States/State.h"

EnterConfigStateCommand::EnterConfigStateCommand() {}

void EnterConfigStateCommand::execute()
{
    setState(new ConfigState);
}