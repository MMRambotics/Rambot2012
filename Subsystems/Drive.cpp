#include "Drive.h"
#include "../RobotMap.h"
#include "../Commands/ArcadeDrive.h"

Drive::Drive() : 
    Subsystem("Drive"),    
    shiftersolenoid(SHIFTER_SOLENOID_PORT_A, SHIFTER_SOLENOID_PORT_B)
{
    rightMotor = new Victor(RIGHT_MOTOR_PORT);
    leftMotor = new Victor(LEFT_MOTOR_PORT);
    drive = new RobotDrive(leftMotor, rightMotor);
    shiftersolenoid.Set(DoubleSolenoid::kForward);
    SetHighGear();
    victorGroup = new VictorGroup(leftMotor, rightMotor, VictorGroup::STRAIGHT);
}
    
void Drive::InitDefaultCommand() {
    SetDefaultCommand(new ArcadeDrive());
}

void Drive::TankDriveFunction(Joystick *leftStick, Joystick *rightStick){
    float leftValue = -leftStick->GetY();
    float rightValue = -rightStick->GetY();
    drive->TankDrive(leftValue, rightValue);
    SmartDashboard::GetInstance()->Log(leftValue, "DriveLeftSpeed");
    SmartDashboard::GetInstance()->Log(rightValue, "DriveRightSpeed");
    SmartDashboard::GetInstance()->Log("Tank", "DriveStyle");
}

void Drive::TankDriveFunction(float leftValue, float rightValue){
    SmartDashboard::GetInstance()->Log("Tank", "DriveStyle");
    SmartDashboard::GetInstance()->Log(-leftValue, "DriveLeftSpeed");
    SmartDashboard::GetInstance()->Log(-rightValue, "DriveRightSpeed");
    drive->TankDrive(-leftValue, -rightValue); 
}

void Drive::TankDriveFunction(KinectStick *leftArm, KinectStick *rightArm){
    drive->TankDrive(leftArm, rightArm);
}

void Drive::ArcadeDriveFunction(Joystick *joystick){
    float speed = -joystick->GetY();
    float rotate = -joystick->GetX();
    drive->ArcadeDrive(speed, rotate);
    SmartDashboard::GetInstance()->Log("Arcade", "DriveStyle");
    SmartDashboard::GetInstance()->Log(speed, "DriveSpeed");
    SmartDashboard::GetInstance()->Log(rotate, "DriveRotate");
}

void Drive::SetHighGear() {
    shiftersolenoid.Set(DoubleSolenoid::kForward);
    gearState = kHighGear;
}

void Drive::SetLowGear() {
    shiftersolenoid.Set(DoubleSolenoid::kReverse);
    gearState = kLowGear;
}

void Drive::SwitchGear() {  
    if (gearState == kHighGear) {
        SetLowGear();
    } else {
        SetHighGear();
    }
}

Drive::GearMode Drive::GetState() {
    return gearState;
}

void Drive::DriveStraight(float speed) {
    
}
