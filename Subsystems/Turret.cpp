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
	setpoint = 0.0;
	
    SmartDashboard::GetInstance()->Log("Stopped", "EncoderStatus");

}
    
void Turret::InitDefaultCommand() {
    SetDefaultCommand(new ManualShooter());
}

void Turret::SetShooterSpeed(float speed) {
    leftShooter->Set(speed);
    rightShooter->Set(speed);
    SmartDashboard::GetInstance()->Log(speed, "ShooterSpeed");
}

void Turret::EnablePIDControl() {
    leftPIDControl->Enable();
    rightPIDControl->Enable();
    SmartDashboard::GetInstance()->Log("Enabled", "ShooterPID");
}

void Turret::DisablePIDControl() {
    leftPIDControl->Disable();
    rightPIDControl->Disable();
    SmartDashboard::GetInstance()->Log("Disabled", "ShooterPID");
}

void Turret::StopShooter() {
    leftShooter->Set(0.0);
    rightShooter->Set(0.0);
}

void Turret::SetRPM(float rpm) {
    leftPIDControl->SetSetpoint(rpm);
    rightPIDControl->SetSetpoint(rpm); 
    setpoint = rpm;
    SmartDashboard::GetInstance()->Log(rpm, "ShooterRPMSetpoint");
}

void Turret::Pan(float value) {
    float speed = value / 4.0;
    panMotor->Set(speed);
    SmartDashboard::GetInstance()->Log(speed, "ShooterPanSpeed");
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
    SmartDashboard::GetInstance()->Log("Started", "EncoderStatus");
}

void Turret::Reset() {
    leftEncoder->Reset();
    rightEncoder->Reset();
}

bool Turret::AtSetpoint() {
    float leftError = setpoint - leftEncoder->GetRPM();
    float rightError = setpoint - rightEncoder->GetRPM();
    if (leftError < 0) leftError *= -1;
    if (rightError < 0) rightError *= -1;
    
    if (rightError < TOLERANCE && leftError < TOLERANCE) {
        return true;
    }
    
    return false;
}
