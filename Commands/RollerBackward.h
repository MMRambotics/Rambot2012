#ifndef ROLLER_BACKWARD_H
#define ROLLER_BACKWARD_H

#include "../CommandBase.h"

class RollerBackward: public CommandBase {
public:
	RollerBackward();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
