#include "LockBike.h"
#include "States/LockedState.h"

LockBike::LockBike() {}

void LockBike::execute()
{
    Serial.println("LOCK BIKE");
    setState(new LockedState);
}
