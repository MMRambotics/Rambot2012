#include "Roller.h"
#include "../RobotMap.h"
#include "../Commands/RollerStop.h"
#include "../Configuration.h"

Roller::Roller() : 
    Subsystem("Roller"), 
    rollerVictor(ROLLER_PORT)
{
    
}
    
void Roller::InitDefaultCommand() {
    
}

void Roller::rollerForward(){
    rollerVictor.Set(ROLLER_SPEED); 
    SmartDashboard::GetInstance()->Log("Forward", "RollerStatus");
}

void Roller::rollerStop(){
    rollerVictor.Set(0.0);
    SmartDashboard::GetInstance()->Log("Stop", "RollerStatus");
}

void Roller::rollerBackward(){
    rollerVictor.Set(-ROLLER_SPEED);
    SmartDashboard::GetInstance()->Log("Reverse", "RollerStatus");
    
}
