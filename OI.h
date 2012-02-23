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
    GamepadButton *rollerForwardButton;
    GamepadButton *rollerStopButton1;
    GamepadButton *rollerStopButton2;
    GamepadButton *rollerBackwardButton;
    GamepadButton *rampDeployButton;
    GamepadButton *rampUndeployButton;
public:
    OI();
    Joystick * GetLeftStick();
    Joystick * GetRightStick();
    F310 * GetGamePad();
    KinectStick * GetLeftArm();
    KinectStick * GetRightArm();
    
};

#endif
