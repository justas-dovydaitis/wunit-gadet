#ifndef __LOCKED_STATE_H__
#define __LOCKED_STATE_H__

#include "State.h"

class LockedState : public AbstractState
{
private:
    /* data */
public:
    void init();
    void destroy();
};

#endif