#ifndef ARCADE_DRIVE_H
#define ARCADE_DRIVE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ArcadeDrive: public CommandBase {
public:
    ArcadeDrive();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
