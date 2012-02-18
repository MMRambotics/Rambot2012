#include "Drive.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"

Drive::Drive() : 
    Subsystem("Drive"),
    rightMotor(RIGHT_MOTOR_PORT),
    leftMotor(LEFT_MOTOR_PORT),
    drive(leftMotor, rightMotor),
    shiftersolenoid(SHIFTER_SOLENOID_PORT_A, SHIFTER_SOLENOID_PORT_B)
{
	victorGroup = new VictorGroup(&leftMotor, &rightMotor);
	com = new SerialPort(9600);
	compass = new TruePoint();
    pCompass = new PitchCompass(compass);
	aCompass = new AzimuthCompass(compass);
	pidControl = new PIDController(DRIVE_STRAIGHT_P, DRIVE_STRAIGHT_I, DRIVE_STRAIGHT_D, aCompass, victorGroup);
}
    
void Drive::InitDefaultCommand() {
    SetDefaultCommand(new TankDrive());
}

void Drive::TankDriveFunction(Joystick *leftStick, Joystick *rightStick){
    pidControl->Disable();
    drive.TankDrive(leftStick,rightStick);
}

void Drive::TankDriveFunction(float leftValue, float rightValue){
    pidControl->Disable();
    drive.TankDrive(leftValue, rightValue); 
}

void Drive::TankDriveFunction(KinectStick leftArm, KinectStick rightArm){
    pidControl->Disable();
    drive.TankDrive(leftArm, rightArm);
}

void Drive::ArcadeDriveFunction(Joystick *joystick){
    pidControl->Disable();
    float speed = joystick->GetY();
    float rotate = joystick->GetX();
    drive.ArcadeDrive(speed, rotate);
}

void Drive::DriveStraight(float speed) {
    victorGroup->SetModeStraight();
    victorGroup->SetSpeed(speed);
    pidControl->Enable();
}

void Drive::SetHighGear() {
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
}
