#ifndef GIANTFOUR_H
#define GIANTFOUR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class GiantFour: public Subsystem {
private:
    DoubleSolenoid giantfoursolenoid;
    DoubleSolenoid ramplocksolenoid;
    Timer *timer;
public:
    GiantFour();
    void InitDefaultCommand();
    void LockRamp();
    void UnlockRamp();
    void RampUp();
    void RampDown();
    Timer * GetTimer();
};

#endif
