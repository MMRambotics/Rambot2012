#ifndef STOPCONVEYOR_H
#define STOPCONVEYOR_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Mike
 */
class StopConveyor: public CommandBase {
public:
	StopConveyor();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
