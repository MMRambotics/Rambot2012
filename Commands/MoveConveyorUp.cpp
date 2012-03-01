#include "MoveConveyorUp.h"

MoveConveyorUp::MoveConveyorUp() {
	Requires(conveyor);
}

// Called just before this Command runs the first time
void MoveConveyorUp::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void MoveConveyorUp::Execute() {
	conveyor->ConveyorUp();
}

// Make this return true when this Command no longer needs to run execute()
bool MoveConveyorUp::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveConveyorUp::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveConveyorUp::Interrupted() {
}
