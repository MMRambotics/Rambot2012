#include "Turret.h"
#include "../RobotMap.h"
#include "../Commands/ManualShooter.h"

Turret::Turret() : Subsystem("Turret") {
	leftShooter = new Jaguar(LEFT_SHOOTER_PORT);
	rightShooter = new Jaguar(RIGHT_SHOOTER_PORT);
}
    
void Turret::InitDefaultCommand() {
	SetDefaultCommand(new ManualShooter());
}

void Turret::SetShooterSpeed(float speed) {
    leftShooter->Set(speed);
    rightShooter->Set(-speed);

}
