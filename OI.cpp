#include "OI.h"
#include "Commands/MoveConveyorUp.h"
#include "Commands/StopConveyor.h"
#include "Commands/MoveConveyorDown.h"
#include "Commands/UndeployRamp.h"
#include "Commands/DeployRamp.h"
#include "Commands/ManualShooter.h"
#include "Commands/AutomaticShooter.h"

OI::OI() {
    leftStick = new Joystick(LEFT_JOYSTICK_PORT);
    rightStick = new Joystick(RIGHT_JOYSTICK_PORT);
    gamePad = new F310(GAME_PAD_PORT);
    leftArm = new KinectStick(LEFT_ARM_PORT);
    rightArm = new KinectStick(RIGHT_ARM_PORT);
    
    rampDeployButton = new GamepadButton(gamePad, F310::kXButton);
    rampUndeployButton = new GamepadButton(gamePad, F310::kBButton);
           
    rampDeployButton->WhenPressed(new DeployRamp());
    rampUndeployButton->WhenPressed(new UndeployRamp());
}

Joystick * OI::GetLeftStick() {
    return leftStick;
}

Joystick * OI::GetRightStick() {
    return rightStick;
}

F310 * OI::GetGamePad() {
    return gamePad;
}

KinectStick * OI::GetLeftArm() {
    return leftArm;
}

KinectStick * OI::GetRightArm() {
    return rightArm;
}

Kinect * OI::GetKinect() {
    return kinect;
}
