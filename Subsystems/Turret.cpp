#include "Turret.h"
#include "../RobotMap.h"
#include "../Commands/ManualShooter.h"
#include "../Configuration.h"
#include "../Commands/AutomaticShooter.h"
 
// Encoder spacing should be 15 thou

Turret::Turret() : Subsystem("Turret") {
	leftShooter = new PIDJaguar(LEFT_SHOOTER_PORT, false);
	rightShooter = new PIDJaguar(RIGHT_SHOOTER_PORT, false);
	leftEncoder = new RateEncoder(LEFT_ENCODER_A_PORT, LEFT_ENCODER_B_PORT, false, 2.0, 0.8);
	rightEncoder = new RateEncoder(RIGHT_ENCODER_A_PORT, RIGHT_ENCODER_B_PORT, true, 1.0, 1.3333334);
	leftPIDControl = new PIDController(TURRET_P, TURRET_I, TURRET_D, leftEncoder, leftShooter);
	rightPIDControl = new PIDController(TURRET_P, TURRET_I, TURRET_D, rightEncoder, rightShooter);
	panMotor = new Jaguar(PAN_MOTOR_PORT);
}
    
void Turret::InitDefaultCommand() {
    SetDefaultCommand(new AutomaticShooter());
}

void Turret::SetShooterSpeed(float speed) {
    leftShooter->Set(speed);
    rightShooter->Set(-speed);
}

void Turret::EnablePIDControl() {
    leftPIDControl->Enable();
    rightPIDControl->Enable();
}

void Turret::DisablePIDControl() {
    leftPIDControl->Disable();
    rightPIDControl->Disable();
}

void Turret::StopShooter() {
    leftShooter->Set(0.0);
    rightShooter->Set(0.0);
}

void Turret::SetRPM(float rpm) {
    leftPIDControl->SetSetpoint(-rpm);
    rightPIDControl->SetSetpoint(rpm);    
}

void Turret::Pan(float value) {
    panMotor->Set(value / 4.0);
}

void Turret::Process() {
    leftEncoder->ProcessData();
    rightEncoder->ProcessData();
    SmartDashboard::GetInstance()->Log(leftEncoder->GetRPM(), "LeftRate");
    SmartDashboard::GetInstance()->Log(rightEncoder->GetRPM(), "RightRate");
    SmartDashboard::GetInstance()->Log(leftEncoder->GetCount(), "LeftCount");
    SmartDashboard::GetInstance()->Log(rightEncoder->GetCount(), "RightCount");
}

void Turret::Start() {
    leftEncoder->Start();
    rightEncoder->Start();
}

void Turret::Reset() {
    leftEncoder->Reset();
    rightEncoder->Reset();
}
