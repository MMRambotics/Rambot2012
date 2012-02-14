#ifndef MANUALSHOOTER_H
#define MANUALSHOOTER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Mike
 */
class ManualShooter: public CommandBase {
public:
	ManualShooter();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
