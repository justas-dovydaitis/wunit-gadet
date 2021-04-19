#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <Arduino.h>

class Command
{
public:
    virtual ~Command()
    {
    }
    virtual void execute() const = 0;
};

#endif