#ifndef __DETECT_STATE_H__
#define __DETECT_STATE_H__

#include "State.h"

class InitState : public AbstractState
{
private:
    /* data */
protected:
    void onInit();
    void onDestroy();
};

#endif