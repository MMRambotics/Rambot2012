#ifndef DEPLOYRAMP_H
#define DEPLOYRAMP_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Mike
 */
class DeployRamp: public CommandBase {
public:
	DeployRamp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
