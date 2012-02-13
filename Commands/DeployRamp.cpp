#include "DeployRamp.h"
#include "../Configuration.h"

DeployRamp::DeployRamp() {
	//Requires(giantFour);
}

// Called just before this Command runs the first time
void DeployRamp::Initialize() {
	//giantFour->GetTimer()->Reset();
	//giantFour->GetTimer()->Start();
}

// Called repeatedly when this Command is scheduled to run
void DeployRamp::Execute() {
	//giantFour->RampDown();
	//if (giantFour->GetTimer()->Get() > RAMP_LOCK_WAIT_TIME) {
	//	giantFour->LockRamp();
	//}
}

// Make this return true when this Command no longer needs to run execute()
bool DeployRamp::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DeployRamp::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DeployRamp::Interrupted() {
}
