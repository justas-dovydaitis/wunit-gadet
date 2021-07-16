#include "CompositeCommand.h"

void AbstractCompositeCommand::add(CommandInterface *command)
{
    this->_children.push_back(command);
}

void AbstractCompositeCommand::execute()
{
    for (CommandInterface *child : _children)
    {
        child->execute();
    }
}