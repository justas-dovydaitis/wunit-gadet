#include "Command.h"

#include "CloseOutputCommand.h"
#include "EnterConfigStateCommand.h"
#include "ExitConfigStateCommand.h"
#include "LockBikeCommand.h"
#include "OpenOutputCommand.h"
#include "PhoneCallCommand.h"
#include "SMSCommand.h"
#include "ToggleOutputCommand.h"
#include "UnlockBikeCommand.h"

Command *createCommand(uint8_t commandIndex, std::string param)
{
    Serial.println(commandIndex);
    Serial.println(param.c_str());

    switch (commandIndex)
    {
    case COMMAND_OPEN_OUTPUT:
        return new OpenOutputCommand(atoi(param.c_str()));
    case COMMAND_CLOSE_OUTPUT:
        return new CloseOutputCommand(atoi(param.c_str()));
    case COMMAND_LOCK_BIKE:
        return new LockBikeCommand();
    case COMMAND_UNLOCK_BIKE:
        return new UnlockBikeCommand();
    case COMMAND_ENTER_CONFIG_STATE:
        return new EnterConfigStateCommand();
    case COMMAND_EXIT_CONFIG_STATE:
        return new ExitConfigStateCommand();
    case COMMAND_TOGGLE_OUTPUT:
        return new ToggleOutputCommand(param);
    case COMMAND_CALL_NUMBER:
        return new PhoneCallCommand(param);
    case COMMAND_SMS:
        return new SMSCommand(param);
    default:
        return nullptr;
    }
}