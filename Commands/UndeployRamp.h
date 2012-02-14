#ifndef UNDEPLOYRAMP_H
#define UNDEPLOYRAMP_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Mike
 */
class UndeployRamp: public CommandBase {
public:
    UndeployRamp();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
