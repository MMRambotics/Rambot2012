#include "Conveyor.h"
#include "../RobotMap.h"
#include "../Configuration.h"

Conveyor::Conveyor() : 
    Subsystem("Conveyor"),
    conveyor(CONVEYOR_PORT)
{
    
}
    
void Conveyor::InitDefaultCommand() {
    
}

void Conveyor::ConveyorDown() {
    conveyor.Set(-CONVEYOR_SPEED);
    SmartDashboard::GetInstance()->Log("Down", "ConveyorStatus");
}

void Conveyor::ConveyorStop() {
    conveyor.Set(0.0);
    SmartDashboard::GetInstance()->Log("Stopped", "ConveyorStatus");
}

void Conveyor::ConveyorUp() {
    conveyor.Set(CONVEYOR_SPEED);
    SmartDashboard::GetInstance()->Log("Up", "ConveyorStatus");
}


