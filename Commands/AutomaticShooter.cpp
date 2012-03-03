#include "AutomaticShooter.h"

AutomaticShooter::AutomaticShooter() {
	Requires(turret);
	rpmSetpoint = 0.0;
	status = kEnabled;
}

// Called just before this Command runs the first time
void AutomaticShooter::Initialize() {
    turret->Start();
	turret->EnablePIDControl();
}

// Called repeatedly when this Command is scheduled to run
void AutomaticShooter::Execute() {
    if (oi->GetGamePad()->GetButton(F310::kLeftBumper)) {
        status = kEnabled;
    } else if (oi->GetGamePad()->GetButton(F310::kRightBumper)) {
        status = kDisabled;
    }
    SmartDashboard::GetInstance()->Log(oi->GetGamePad()->GetButton(F310::kLeftBumper), "Left Bumper");
    SmartDashboard::GetInstance()->Log(oi->GetGamePad()->GetButton(F310::kRightBumper), "Right Bumper");
    if (status == kEnabled) {
        float speed = -oi->GetGamePad()->GetY(F310::kRightStick);
        float scale = 15;
        rpmSetpoint += speed * scale;
        turret->Process();
        if (rpmSetpoint < 0.0) { rpmSetpoint = 0.0; }
        SmartDashboard::GetInstance()->PutDouble("RPMSetpoint", rpmSetpoint);
        turret->SetRPM(rpmSetpoint);
    } else {
        turret->SetShooterSpeed(0.0);
    }
    
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
