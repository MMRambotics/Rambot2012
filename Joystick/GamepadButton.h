#ifndef GAMEPAD_BUTTON_H
#define GAMEPAD_BUTTON_H

#include "WPILib.h"
#include "F310.h"

class GamepadButton : public Button {
    F310 * gamepad;
    F310::ButtonType button;
public:
    GamepadButton(F310 * controller, F310::ButtonType buttonToPress);
    virtual bool Get();
    
};

#endif
