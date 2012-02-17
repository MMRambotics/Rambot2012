#include "AutomaticShooter.h"

AutomaticShooter::AutomaticShooter() {
	Requires(turret);
}

// Called just before this Command runs the first time
void AutomaticShooter::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AutomaticShooter::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool AutomaticShooter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutomaticShooter::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutomaticShooter::Interrupted() {
}
