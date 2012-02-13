#ifndef ROLLER_H
#define ROLLER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Roller: public Subsystem {
private:
	
public:
	Jaguar rollerVictor;
	Roller();
	void InitDefaultCommand();
	void rollerForward();
	void rollerStop();
	void rollerBackward();
};

#endif
