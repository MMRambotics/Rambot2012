#ifndef DRIVE_H
#define DRIVE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../VictorGroup.h"
#include "../TruePoint/TruePoint.h"
#include "../TruePoint/PitchCompass.h"
#include "../TruePoint/AzimuthCompass.h"
#include "../Configuration.h"

class Drive: public Subsystem {
private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
public:	
    typedef enum
    {
        kLowGear,
        kHighGear,
    } GearMode;
    
	Victor *rightMotor;
	Victor *leftMotor;
	VictorGroup *victorGroup;
	RobotDrive *drive;
	
	DoubleSolenoid shiftersolenoid;

	GearMode gearState;
	
	Drive();
	void InitDefaultCommand();
	void TankDriveFunction(Joystick *leftJoystick, Joystick *rightJoystick);
	void TankDriveFunction(float leftValue, float rightValue);
	void TankDriveFunction(KinectStick *leftArm, KinectStick *rightArm);
	void ArcadeDriveFunction(Joystick *joystick);
	void SetHighGear();
	void SetLowGear();
	void SwitchGear();
	GearMode GetState();
	void DriveStraight(float speed);
};

#endif
