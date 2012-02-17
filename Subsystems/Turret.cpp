#include "Turret.h"
#include "../RobotMap.h"
#include "../Commands/ManualShooter.h"
#include "../Configuration.h"

Turret::Turret() : Subsystem("Turret") {
	leftShooter = new PIDJaguar(LEFT_SHOOTER_PORT);
	rightShooter = new PIDJaguar(RIGHT_SHOOTER_PORT);
	leftEncoder = new RateEncoder(LEFT_ENCODER_A_PORT, LEFT_ENCODER_B_PORT, true);
	rightEncoder = new RateEncoder(RIGHT_ENCODER_A_PORT, RIGHT_ENCODER_B_PORT, true);
	leftPIDControl = new PIDController(TURRET_P, TURRET_I, TURRET_D, leftEncoder, leftShooter);
	rightPIDControl = new PIDController(TURRET_P, TURRET_I, TURRET_D, rightEncoder, rightShooter);
	panMotor = new Jaguar(PAN_MOTOR_PORT);
}
    
void Turret::InitDefaultCommand() {

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
    leftPIDControl->SetSetpoint(rpm);
    rightPIDControl->SetSetpoint(rpm);
}

void Turret::Pan(float value) {
    panMotor->Set(value / 4.0);
}
