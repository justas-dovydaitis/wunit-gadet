#ifndef __UNLOCKED_STATE_H__
#define __UNLOCKED_STATE_H__

#include "State.h"

class UnlockedState : public AbstractState
{
private:
    /* data */
public:
    void init();
    void destroy();
};

#endif