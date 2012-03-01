#ifndef MOVECONVEYORUP_H
#define MOVECONVEYORUP_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Mike
 */
class MoveConveyorUp: public CommandBase {
public:
	MoveConveyorUp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
