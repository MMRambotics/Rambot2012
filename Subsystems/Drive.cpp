#include "Drive.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"

Drive::Drive() : 
	Subsystem("Drive"),
	rightMotor(RIGHT_MOTOR_PORT),
	leftMotor(LEFT_MOTOR_PORT),
	drive(leftMotor, rightMotor)//,
	//shiftersolenoid(SHIFTER_SOLENOID_A_PORT, SHIFTER_SOLENOID_B_PORT)
{
	
}
    
void Drive::InitDefaultCommand() {
	SetDefaultCommand(new TankDrive());
}

void Drive::TankDriveFunction(Joystick *leftStick, Joystick *rightStick){
	drive.TankDrive(leftStick,rightStick);
}

void Drive::TankDriveFunction(float leftValue, float rightValue){
	drive.TankDrive(leftValue, rightValue); 
}

void Drive::TankDriveFunction(KinectStick leftArm, KinectStick rightArm){
	drive.TankDrive(leftArm, rightArm);
}

void Drive::ArcadeDriveFunction(Joystick *joystick){
	float speed = joystick->GetY();
	float rotate = -joystick->GetX();
	drive.ArcadeDrive(speed, rotate);
}

/*void Drive::SetHighGear() {
	shiftersolenoid.Set(DoubleSolenoid::kForward);
}

void Drive::SetLowGear() {
	shiftersolenoid.Set(DoubleSolenoid::kReverse);
}

void Drive::SwitchGear() {
	if (gearState == kHighGear) {
		SetLowGear();
		gearState = kLowGear;
	} else {
		SetHighGear();
		gearState = kHighGear;
	}
}*/
