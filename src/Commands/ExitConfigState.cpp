#include "ExitConfigState.h"
#include "States/State.h"
#include "States/UnlockedState.h"

ExitConfigState::ExitConfigState() {}

void ExitConfigState::execute()
{
    setState(new UnlockedState);
}