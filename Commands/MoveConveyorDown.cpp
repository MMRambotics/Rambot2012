#include "MoveConveyorDown.h"

MoveConveyorDown::MoveConveyorDown() {
	Requires(conveyor);
}

// Called just before this Command runs the first time
void MoveConveyorDown::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void MoveConveyorDown::Execute() {
	conveyor->ConveyorDown();
}

// Make this return true when this Command no longer needs to run execute()
bool MoveConveyorDown::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveConveyorDown::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveConveyorDown::Interrupted() {
}
