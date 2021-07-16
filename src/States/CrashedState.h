#ifndef __CRASH_STATE_H__
#define __CRASH_STATE_H__

#include "State.h"

class CrashedState : public AbstractState
{

    const uint16_t _currentStateId = StateId_t::CRASHED_STATE;

private:
    void onInit();
    void onDestroy();
};

#endif