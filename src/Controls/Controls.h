#ifndef __CONTROLS_H__
#define __CONTROLS_H__

#include <Arduino.h>
#include <FreeRTOS.h>

class Button
{
protected:
    TaskFunction_t _assignedTask;
    TaskHandle_t _taskHandle;

public:
    Button(TaskFunction_t assignedTask);

    virtual void switchOn() = 0;
    virtual void switchOff() = 0;
};

class MomentaryButton : public Button
{
public:
    MomentaryButton(TaskFunction_t assignedTask);
    void switchOn() override;
    void switchOff() override;
};

class LatchingButton : public Button
{
private:
    bool _status = false;

public:
    LatchingButton(TaskFunction_t assignedTask);
    void switchOn() override;
    void switchOff() override;
};

#endif