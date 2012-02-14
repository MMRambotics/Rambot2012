#ifndef CONVEYOR_H
#define CONVEYOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Conveyor: public Subsystem {
private:
    Jaguar conveyor;
public:
    Conveyor();
    void InitDefaultCommand();
    void ConveyorUp();
    void ConveyorStop();
    void ConveyorDown();
};

#endif
