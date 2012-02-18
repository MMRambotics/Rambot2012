#include "OI.h"
#include "Commands/RollerForward.h"
#include "Commands/RollerStop.h"
#include "Commands/RollerBackward.h"
#include "Commands/UndeployRamp.h"
#include "Commands/DeployRamp.h"
#include "Commands/ManualShooter.h"
#include "Commands/StraightWithJoystick.h"

OI::OI() {
    leftStick = new Joystick(LEFT_JOYSTICK_PORT);
    rightStick = new Joystick(RIGHT_JOYSTICK_PORT);
    gamePad = new F310(GAME_PAD_PORT);
    leftArm = new KinectStick(LEFT_ARM_PORT);
    rightArm = new KinectStick(RIGHT_ARM_PORT);
    
    rollerForwardButton = new GamepadButton(gamePad, F310::kYButton);
    rollerStopButton1 = new GamepadButton(gamePad, F310::kBButton);
    rollerStopButton2 = new GamepadButton(gamePad, F310::kXButton);
    rollerBackwardButton = new GamepadButton(gamePad, F310::kAButton);
    rampDeployButton = new GamepadButton(gamePad, F310::kRightBumper);
    rampUndeployButton = new GamepadButton(gamePad, F310::kLeftBumper);
    driveStraightButton = new JoystickButton(leftStick, DRIVE_STRAIGHT_BUTTON);
        
    rollerForwardButton->WhenPressed(new RollerForward());
    rollerStopButton1->WhenPressed(new RollerStop());    
    rollerStopButton2->WhenPressed(new RollerStop());    
    rollerBackwardButton->WhenPressed(new RollerBackward());    
    rampDeployButton->WhenPressed(new DeployRamp());
    rampUndeployButton->WhenPressed(new UndeployRamp());
    driveStraightButton->WhileHeld(new StraightWithJoystick());

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
