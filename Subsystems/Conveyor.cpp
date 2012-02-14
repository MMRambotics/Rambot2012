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
}

void Conveyor::ConveyorStop() {
    conveyor.Set(0.0);
}

void Conveyor::ConveyorUp() {
    conveyor.Set(CONVEYOR_SPEED);
}


