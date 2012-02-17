#include "IterativeTurret.h"

IterativeTurret::IterativeTurret() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void IterativeTurret::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void IterativeTurret::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool IterativeTurret::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IterativeTurret::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IterativeTurret::Interrupted() {
}
