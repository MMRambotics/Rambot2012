#include "RollerStop.h"

RollerStop::RollerStop() {
	Requires(roller);
}
// Called just before this Command runs the first time
void RollerStop::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void RollerStop::Execute() {
	roller->rollerStop();
}

// Make this return true when this Command no longer needs to run execute()
bool RollerStop::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RollerStop::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RollerStop::Interrupted() {
}
