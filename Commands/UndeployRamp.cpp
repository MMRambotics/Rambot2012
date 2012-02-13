#include "UndeployRamp.h"
#include "../Configuration.h"

UndeployRamp::UndeployRamp() {
	//Requires(giantFour);
}

// Called just before this Command runs the first time
void UndeployRamp::Initialize() {
	//giantFour->GetTimer()->Reset();
	//giantFour->GetTimer()->Start();
}

// Called repeatedly when this Command is scheduled to run
void UndeployRamp::Execute() {
	//giantFour->UnlockRamp();
	//if (giantFour->GetTimer()->Get() > RAMP_LOCK_WAIT_TIME) {
	//	giantFour->RampUp();
	//}
}

// Make this return true when this Command no longer needs to run execute()
bool UndeployRamp::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void UndeployRamp::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UndeployRamp::Interrupted() {
}
