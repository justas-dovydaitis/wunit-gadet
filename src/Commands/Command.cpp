#include "Command.h"

#include "CloseOutputCommand.h"
#include "LockBikeCommand.h"
#include "OpenOutputCommand.h"
#include "UnlockBikeCommand.h"

Command *createCommand(uint8_t commandIndex, void *pCommandParam = nullptr)
{
    switch (commandIndex)
    {
    case COMMAND_OPEN_OUTPUT:
        return new OpenOutputCommand(*(uint8_t *)pCommandParam);
    case COMMAND_CLOSE_OUTPUT:
        return new CloseOutputCommand(*(uint8_t *)pCommandParam);
    case COMMAND_LOCK_BIKE:
        return new LockBikeCommand();
    case COMMAND_UNLOCK_BIKE:
        return new UnlockBikeCommand();
    default:
        return nullptr;
    }
}