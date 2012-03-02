#include "GiantFour.h"
#include "../RobotMap.h"

GiantFour::GiantFour():
    Subsystem("GiantFour"),
    giantfoursolenoid(GIANT_FOUR_SOLENOID_A_PORT, GIANT_FOUR_SOLENOID_B_PORT),
    ramplocksolenoid(RAMP_LOCK_SOLENOID_A_PORT, RAMP_LOCK_SOLENOID_B_PORT)
{
    timer = new Timer();
    RampUp();
}
    
void GiantFour::InitDefaultCommand() {

}

void GiantFour::RampUp() {
    giantfoursolenoid.Set(DoubleSolenoid::kForward);
    rampState = kRampUp;
}

void GiantFour::RampDown() {
    giantfoursolenoid.Set(DoubleSolenoid::kReverse);
    rampState = kRampDown;
}

void GiantFour::LockRamp() {
    ramplocksolenoid.Set(DoubleSolenoid::kForward);
}

void GiantFour::UnlockRamp() {
    ramplocksolenoid.Set(DoubleSolenoid::kReverse);
}

GiantFour::RampMode GiantFour::GetState() {
    return rampState;
}

Timer * GiantFour::GetTimer() {
    return timer;
}


