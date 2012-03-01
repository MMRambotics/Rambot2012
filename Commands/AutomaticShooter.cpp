#include "AutomaticShooter.h"

AutomaticShooter::AutomaticShooter() {
	Requires(turret);
}

// Called just before this Command runs the first time
void AutomaticShooter::Initialize() {
    turret->Start();
	turret->EnablePIDControl();
	turret->SetRPM(1500);
}

// Called repeatedly when this Command is scheduled to run
void AutomaticShooter::Execute() {
	turret->Process();
	/*if (oi->GetLeftStick()->GetRawButton(11)) {
	    turret->SetRPM(1000);	    
	} else if (oi->GetLeftStick()->GetRawButton(10)) {
	    turret->SetRPM(1500);
	}*/ 
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
