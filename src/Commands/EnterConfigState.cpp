#include "EnterConfigState.h"
#include "States/ConfigState.h"
#include "States/State.h"

EnterConfigState::EnterConfigState() {}

void EnterConfigState::execute()
{
    setState(new ConfigState);
}