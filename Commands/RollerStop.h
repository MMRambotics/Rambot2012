#ifndef ROLLER_STOP_H
#define ROLLER_STOP_H

#include "../CommandBase.h"

class RollerStop: public CommandBase {
public:
    RollerStop();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
