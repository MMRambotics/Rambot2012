#ifndef ITERATIVETURRET_H
#define ITERATIVETURRET_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Mike
 */
class IterativeTurret: public CommandBase {
public:
	IterativeTurret();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
