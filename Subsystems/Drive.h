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
	
	Victor rightMotor;
	Victor leftMotor;
	RobotDrive drive;
	VictorGroup *victorGroup;
	PIDController *pidControl;
	SerialPort *com;
	TruePoint *compass;
	PitchCompass *pCompass;
	AzimuthCompass *aCompass;
	
	//DoubleSolenoid shiftersolenoid;
	
	GearMode gearState;
	
	Drive();
	void InitDefaultCommand();
	void TankDriveFunction(Joystick *leftJoystick, Joystick *rightJoystick);
	void TankDriveFunction(float leftValue, float rightValue);
	void TankDriveFunction(KinectStick leftArm, KinectStick rightArm);
	void ArcadeDriveFunction(Joystick *joystick);
	void DriveStraight(float speed);
	//void SetHighGear();
	//void SetLowGear();
	//void SwitchGear();

};

#endif
