#ifndef ROLLER_FORWARD_H
#define ROLLER_FORWARD_H

#include "../CommandBase.h"

class RollerForward: public CommandBase {
public:
	RollerForward();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
