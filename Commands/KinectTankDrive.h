#ifndef KINECT_TANK_DRIVE_H
#define KINECT_TANK_DRIVE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class KinectTankDrive: public CommandBase {
    
public:
	KinectTankDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
