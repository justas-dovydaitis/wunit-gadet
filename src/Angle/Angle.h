#ifndef __ANGLE_H__
#define __ANGLE_H__

#include <Arduino.h>

#define DEFAULT_ANGLE_COMPENSATE 0
#define RADIAN 57.292779524

extern long angleCompensate;

extern void setupAngle();
extern long getCurrentAngle();
extern void setAngleCompensate(float compensate);
extern void adjustAngleCompensate(float compensateAdjustVal);
extern void setCurrentAngleToZero();


#endif