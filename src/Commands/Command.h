#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <Arduino.h>

enum CommandIndex_t : uint8_t
{
    COMMAND_OPEN_OUTPUT = 0,
    COMMAND_CLOSE_OUTPUT = 1,
    COMMAND_TOGGLE_OUTPUT = 2,
    COMMAND_LOCK_BIKE = 3,
    COMMAND_UNLOCK_BIKE = 4,
    COMMAND_ENTER_CONFIG_STATE = 5,
    COMMAND_EXIT_CONFIG_STATE = 6,
    COMMAND_CALL_NUMBER = 7,
    COMMAND_SMS = 8
};

class CommandInterface
{
public:
    virtual ~CommandInterface() {}
    virtual void execute() = 0;
};

CommandInterface *createCommand(uint8_t commandIndex, std::string param);

#endif