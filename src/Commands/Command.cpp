#include "Command.h"

#include "CloseOutputCommand.h"
#include "EnterConfigStateCommand.h"
#include "ExitConfigStateCommand.h"
#include "LockBikeCommand.h"
#include "OpenOutputCommand.h"
#include "ToggleOutputCommand.h"
#include "UnlockBikeCommand.h"

Command *createCommand(uint8_t commandIndex, void *pCommandParam = nullptr)
{
    uint *pParam = static_cast<uint *>(pCommandParam);
    switch (commandIndex)
    {
    case COMMAND_OPEN_OUTPUT:
        Serial.println((uint8_t)*pParam);
        return new OpenOutputCommand((uint8_t)*pParam);
    case COMMAND_CLOSE_OUTPUT:
        return new CloseOutputCommand((uint8_t)*pParam);
    case COMMAND_LOCK_BIKE:
        return new LockBikeCommand();
    case COMMAND_UNLOCK_BIKE:
        return new UnlockBikeCommand();
    case COMMAND_ENTER_CONFIG_STATE:
        return new EnterConfigStateCommand();
    case COMMAND_EXIT_CONFIG_STATE:
        return new ExitConfigStateCommand();
    case COMMAND_TOGGLE_OUTPUT:
        return new ToggleOutputCommand(*pParam++, *pParam);
    default:
        return nullptr;
    }
}