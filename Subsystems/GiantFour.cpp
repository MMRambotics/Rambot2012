#include "GiantFour.h"
#include "../RobotMap.h"

GiantFour::GiantFour():
    Subsystem("GiantFour"),
    giantfoursolenoid(GIANT_FOUR_SOLENOID_A_PORT, GIANT_FOUR_SOLENOID_B_PORT),
    ramplocksolenoid(RAMP_LOCK_SOLENOID_A_PORT, RAMP_LOCK_SOLENOID_B_PORT)
{
    timer = new Timer();
}
    
void GiantFour::InitDefaultCommand() {

}

void GiantFour::RampUp() {
    giantfoursolenoid.Set(DoubleSolenoid::kForward);
}

void GiantFour::RampDown() {
    giantfoursolenoid.Set(DoubleSolenoid::kReverse);
}

void GiantFour::LockRamp() {
    ramplocksolenoid.Set(DoubleSolenoid::kForward);
}

void GiantFour::UnlockRamp() {
    ramplocksolenoid.Set(DoubleSolenoid::kReverse);
}

Timer * GiantFour::GetTimer() {
    return timer;
}


