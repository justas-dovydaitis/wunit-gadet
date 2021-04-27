#include "UnlockBike.h"
#include "States/UnlockedState.h"

UnlockBike::UnlockBike() {}

void UnlockBike::execute()
{
    setState(new UnlockedState);
}
