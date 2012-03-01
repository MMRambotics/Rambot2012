#ifndef MOVECONVEYORDOWN_H
#define MOVECONVEYORDOWN_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Mike
 */
class MoveConveyorDown: public CommandBase {
public:
	MoveConveyorDown();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
