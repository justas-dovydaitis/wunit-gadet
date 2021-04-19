#include "LockBikeCommand.h"
#include "States/LockedState.h"

LockBikeCommand::LockBikeCommand() {}

void LockBikeCommand::execute() const
{
    Serial.println("LOCK BIKE");
    setState(new LockedState);
