#include "Command.h"

#include "CloseOutput.h"
#include "EnterConfigState.h"
#include "ExitConfigState.h"
#include "LockBike.h"
#include "OpenOutput.h"
#include "PhoneCall.h"
#include "SMS.h"
#include "ToggleOutput.h"
#include "UnlockBike.h"

Command *createCommand(uint8_t commandIndex, std::string param)
{
    Serial.println(commandIndex);
    Serial.println(param.c_str());

    switch (commandIndex)
    {
    case COMMAND_OPEN_OUTPUT:
        return new OpenOutput(atoi(param.c_str()));
    case COMMAND_CLOSE_OUTPUT:
        return new CloseOutput(atoi(param.c_str()));
    case COMMAND_LOCK_BIKE:
        return new LockBike();
    case COMMAND_UNLOCK_BIKE:
        return new UnlockBike();
    case COMMAND_ENTER_CONFIG_STATE:
        return new EnterConfigState();
    case COMMAND_EXIT_CONFIG_STATE:
        return new ExitConfigState();
    case COMMAND_TOGGLE_OUTPUT:
        return new ToggleOutput(param);
    case COMMAND_CALL_NUMBER:
        return new PhoneCall(param);
    case COMMAND_SMS:
        return new SMS(param);
    default:
        return nullptr;
    }
}