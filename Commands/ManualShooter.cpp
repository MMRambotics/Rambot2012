#include "ManualShooter.h"
#include "../Joystick/F310.h"

ManualShooter::ManualShooter() {
	Requires(turret);
}

// Called just before this Command runs the first time
void ManualShooter::Initialize() {
    turret->Reset();
	turret->Start();
	turret->DisablePIDControl();
}

// Called repeatedly when this Command is scheduled to run
void ManualShooter::Execute() {
	turret->SetShooterSpeed(-oi->GetGamePad()->GetY(F310::kRightStick));
	turret->Process();
}

// Make this return true when this Command no longer needs to run execute()
bool ManualShooter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ManualShooter::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManualShooter::Interrupted() {
}
