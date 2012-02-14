#include "VictorGroup.h"

VictorGroup::VictorGroup(Victor *leftVictor, Victor *rightVictor, Type type) {
    leftMotor = leftVictor;
    rightMotor = rightVictor;
    
    defaultSpeed = 0.0;
    
    mode = type;
}

void VictorGroup::PIDWrite(float output) {
    float rightSpeed = 0.0;
    float leftSpeed = 0.0;
    
    if (mode == STRAIGHT) {
        rightSpeed = defaultSpeed - output;
        leftSpeed = -(defaultSpeed + output);
    } else if (mode == TURN) {
        rightSpeed = -output;
        leftSpeed = -output;
    }
    
    leftMotor->PIDWrite(leftSpeed);
    rightMotor->PIDWrite(rightSpeed);
    
    SmartDashboard::GetInstance()->Log(leftSpeed, "Left Motors");
    SmartDashboard::GetInstance()->Log(rightSpeed, "Right Motors");
}

void VictorGroup::SetSpeed(float speed) {
    defaultSpeed = speed;
}

void VictorGroup::SetModeStraight() {
    mode = STRAIGHT;
}

void VictorGroup::SetModeTurn() {
    mode = TURN;
}
