#ifndef TURRET_H
#define TURRET_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RateEncoder.cpp"
#include "../PIDJaguar.cpp"

class Turret: public Subsystem {
private:

	PIDJaguar *leftShooter;
	PIDJaguar *rightShooter;
	Jaguar *panMotor;
	RateEncoder *leftEncoder;
	RateEncoder *rightEncoder;
	PIDController *leftPIDControl;
	PIDController *rightPIDControl;
public:
	Turret();
	void InitDefaultCommand();
	void SetShooterSpeed(float speed);
	void EnablePIDControl();
	void DisablePIDControl();
	void StopShooter();
	void SetRPM(float rpm);
	void Pan(float value);
	void Process();
	void Start();
	void Reset();
};

#endif
