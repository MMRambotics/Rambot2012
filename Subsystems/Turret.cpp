#include "Turret.h"
#include "../RobotMap.h"
#include "../Commands/ManualShooter.h"
#include "../Configuration.h"
#include "../Commands/AutomaticShooter.h"
 
// Encoder spacing should be 15 thou

Turret::Turret() : Subsystem("Turret") {
	leftShooter = new PIDJaguar(LEFT_SHOOTER_PORT, true);
	rightShooter = new PIDJaguar(RIGHT_SHOOTER_PORT, false);
	leftEncoder = new RateEncoder(LEFT_ENCODER_A_PORT, LEFT_ENCODER_B_PORT, false, 1.0);
	rightEncoder = new RateEncoder(RIGHT_ENCODER_A_PORT, RIGHT_ENCODER_B_PORT, true, 2.0);
	leftPIDControl = new PIDController(TURRET_P_LEFT, TURRET_I_LEFT, TURRET_D_LEFT, leftEncoder, leftShooter);
	rightPIDControl = new PIDController(TURRET_P_RIGHT, TURRET_I_RIGHT, TURRET_D_RIGHT, rightEncoder, rightShooter);
	panMotor = new Jaguar(PAN_MOTOR_PORT);
	leftPIDControl->SetTolerance(1.0);
	rightPIDControl->SetTolerance(1.0);
}
    
void Turret::InitDefaultCommand() {
    SetDefaultCommand(new AutomaticShooter());
}

void Turret::SetShooterSpeed(float speed) {
    leftShooter->Set(speed);
    rightShooter->Set(speed);
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
    leftPIDControl->SetSetpoint(rpm);
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
    SmartDashboard::GetInstance()->Log(rightPIDControl->GetError(), "RightError");
    SmartDashboard::GetInstance()->Log(leftPIDControl->GetError(), "LeftError");
    SmartDashboard::GetInstance()->Log(rightPIDControl->GetSetpoint(), "Setpoint");
}

void Turret::Start() {
    leftEncoder->Start();
    rightEncoder->Start();
}

void Turret::Reset() {
    leftEncoder->Reset();
    rightEncoder->Reset();
}
