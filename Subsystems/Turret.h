#ifndef TURRET_H
#define TURRET_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Turret: public Subsystem {
private:

	Jaguar *leftShooter;
	Jaguar *rightShooter;
public:
	Turret();
	void InitDefaultCommand();
	void SetShooterSpeed(float speed);

};

#endif
