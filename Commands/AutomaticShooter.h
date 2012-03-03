#ifndef AUTOMATICSHOOTER_H
#define AUTOMATICSHOOTER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Mike
 */
class AutomaticShooter: public CommandBase {
    float rpmSetpoint;
    typedef enum
    {
        kEnabled,
        kDisabled,
    } ShooterStatus;
    ShooterStatus status;
public:
	AutomaticShooter();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
