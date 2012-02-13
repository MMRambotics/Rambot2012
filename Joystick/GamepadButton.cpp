#include "GamepadButton.h"

GamepadButton::GamepadButton(F310 * controller, F310::ButtonType buttonToPress) {
	gamepad = controller;
	button = buttonToPress;
}

bool GamepadButton::Get() {
	return gamepad->GetButton(button);
}
