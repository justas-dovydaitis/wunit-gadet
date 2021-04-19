#ifndef __RUNNING_STATE_H__
#define __RUNNING_STATE_H__

#include "State.h"

class RunningState : public AbstractState
{
public:
    void init();
    void destroy();
    static void blink(void *param);
};

#endif