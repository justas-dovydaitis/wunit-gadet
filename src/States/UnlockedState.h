#ifndef __UNLOCKED_STATE_H__
#define __UNLOCKED_STATE_H__

#include "State.h"
#include "Tasks/Tasks.h"
#include "Controls/Controls.h"

class UnlockedState : public AbstractState
{
private:
    const uint16_t _currentStateId = StateId_t::UNLOCKED_STATE;

protected:
    void onInit();
    void onDestroy();
};

#endif