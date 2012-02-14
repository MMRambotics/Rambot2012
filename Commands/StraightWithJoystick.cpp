#include "StraightWithJoystick.h"

StraightWithJoystick::StraightWithJoystick() {
	Requires(drive);
}

// Called just before this Command runs the first time
void StraightWithJoystick::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void StraightWithJoystick::Execute() {
	drive->DriveStraight(oi->GetLeftStick()->GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool StraightWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void StraightWithJoystick::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StraightWithJoystick::Interrupted() {
}
