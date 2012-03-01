#include "KinectTankDrive.h"

KinectTankDrive::KinectTankDrive() {
	Requires(drive);
}

// Called just before this Command runs the first time
void KinectTankDrive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void KinectTankDrive::Execute() {
	drive->TankDriveFunction(oi->GetLeftArm(),oi->GetRightArm());
}

// Make this return true when this Command no longer needs to run execute()
bool KinectTankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void KinectTankDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void KinectTankDrive::Interrupted() {
}
