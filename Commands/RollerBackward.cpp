#include "RollerBackward.h"

RollerBackward::RollerBackward() {
    Requires(roller);
}
// Called just before this Command runs the first time
void RollerBackward::Initialize() {
    
}

// Called repeatedly when this Command is scheduled to run
void RollerBackward::Execute() {
    roller->rollerBackward();
}

// Make this return true when this Command no longer needs to run execute()
bool RollerBackward::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void RollerBackward::End() {
    
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RollerBackward::Interrupted() {
}
