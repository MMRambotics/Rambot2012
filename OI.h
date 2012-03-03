#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Joystick/F310.h"
#include "RobotMap.h"
#include "Joystick/GamepadButton.h"

class OI {
private:
    Joystick *leftStick;
    Joystick *rightStick;
    F310 *gamePad;
    KinectStick *leftArm;
    KinectStick *rightArm;
    GamepadButton *conveyorUpButton;
    GamepadButton *conveyorStopButton1;
    GamepadButton *conveyorStopButton2;
    GamepadButton *conveyorDownButton;
    Kinect *kinect;
    GamepadButton *rampDeployButton;
    GamepadButton *rampUndeployButton;
public:
    OI();
    Joystick * GetLeftStick();
    Joystick * GetRightStick();
    F310 * GetGamePad();
    KinectStick * GetLeftArm();
    KinectStick * GetRightArm();
    Kinect * GetKinect();
    
};

#endif
