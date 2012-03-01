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
    typedef enum
    {
        kRampDown,
        kRampUp,
    } RampMode;
    RampMode rampState;
    GiantFour();
    void InitDefaultCommand();
    void LockRamp();
    void UnlockRamp();
    void RampUp();
    void RampDown();
    Timer * GetTimer();
    RampMode GetState();
};

#endif
