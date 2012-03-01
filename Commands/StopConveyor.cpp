#include "StopConveyor.h"

StopConveyor::StopConveyor() {
	Requires(conveyor);
}

// Called just before this Command runs the first time
void StopConveyor::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void StopConveyor::Execute() {
	conveyor->ConveyorStop();
}

// Make this return true when this Command no longer needs to run execute()
bool StopConveyor::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void StopConveyor::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopConveyor::Interrupted() {
}
