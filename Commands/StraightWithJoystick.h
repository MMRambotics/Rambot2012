#ifndef STRAIGHTWITHJOYSTICK_H
#define STRAIGHTWITHJOYSTICK_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Mike
 */
class StraightWithJoystick: public CommandBase {
public:
	StraightWithJoystick();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
