#ifndef VICTORGROUP
#define VICTORGROUP

#include "WPILib.h"

class VictorGroup : public PIDOutput {
	enum Type {STRAIGHT, TURN};
	
	Victor *leftMotor;
	Victor *rightMotor;
	float defaultSpeed;
	Type mode;
	
public:
	VictorGroup(Victor *leftVictor, Victor *rightVictor, Type type = TURN);
	virtual void PIDWrite(float output);
	void SetSpeed(float speed);
	void SetModeStraight();
	void SetModeTurn();
};

#endif

