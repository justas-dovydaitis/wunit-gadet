#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <Arduino.h>

enum CommandIndex_t : uint8_t
{
    COMMAND_OPEN_OUTPUT = 0,
    COMMAND_CLOSE_OUTPUT = 1,
    COMMAND_LOCK_BIKE = 2,
    COMMAND_UNLOCK_BIKE = 3,
};

class Command
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

Command *createCommand(uint8_t commandIndex, void *pCommandParam);

#endif