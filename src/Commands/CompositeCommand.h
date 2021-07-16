#ifndef __COMPOSITE_COMMAND_H__
#define __COMPOSITE_COMMAND_H__

#include "Command.h"

#include <list>

class AbstractCompositeCommand : public CommandInterface
{
protected:
    std::list<CommandInterface *> _children;

public:
    void add(CommandInterface *command);
    void execute() override;
};



#endif