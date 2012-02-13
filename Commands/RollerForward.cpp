#include "RollerForward.h"

RollerForward::RollerForward() {
	Requires(roller);
}
// Called just before this Command runs the first time
void RollerForward::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void RollerForward::Execute() {
	roller->rollerForward();
}

// Make this return true when this Command no longer needs to run execute()
bool RollerForward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RollerForward::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RollerForward::Interrupted() {
}
