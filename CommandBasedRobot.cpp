#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/ArcadeDrive.h"
#include "Commands/TankDrive.h"
#include "Commands/KinectTankDrive.h"
#include "Commands/DeployRamp.h"
#include "Commands/UndeployRamp.h"

class CommandBasedRobot : public IterativeRobot {
private:
    Compressor *compressor;
    Command *driveCommand;
    SendableChooser *driveStyle;
    
    bool previousShiftTrigger;
    bool currentShiftTrigger;
    bool previousRampTrigger;
    bool currentRampTrigger;

public:    
    CommandBasedRobot() {
        compressor = new Compressor(PRESSURE_SWITCH_PORT, COMPRESSOR_RELAY_PORT);
        compressor->Start();
        
        driveStyle = new SendableChooser();
        driveStyle->AddDefault("Arcade", new ArcadeDrive());
        driveStyle->AddObject("Tank", new TankDrive());
        
        CommandBase::init();
    }
    
    virtual void RobotInit() {
        NetworkTable::Initialize();
    }
    
    virtual void AutonomousInit() {

    }
    
    virtual void AutonomousPeriodic() {
    }
    
    virtual void TeleopInit() {        
        CommandBase::turret->Reset();
        CommandBase::turret->Start();
        
        driveCommand = (Command*) driveStyle->GetSelected();
        driveCommand->Start();
    }
    
    virtual void TeleopPeriodic() {      
        // Shift Gears
        currentShiftTrigger = CommandBase::oi->GetLeftStick()->GetRawButton(1);
        if (currentShiftTrigger !=  previousShiftTrigger && currentShiftTrigger == false) {
            CommandBase::drive->SwitchGear();
        }
        previousShiftTrigger = currentShiftTrigger;
        
        // Operate Conveyor
        if (CommandBase::oi->GetGamePad()->GetDPadY() > 0.0) {
            CommandBase::conveyor->ConveyorUp();
        } else if (CommandBase::oi->GetGamePad()->GetDPadY() < 0.0) {
            CommandBase::conveyor->ConveyorDown();
        } else {
            CommandBase::conveyor->ConveyorStop();
        }
        
        // Operate Roller
        if (CommandBase::oi->GetGamePad()->GetButton(F310::kAButton)) {
            CommandBase::roller->rollerForward();
        } else if (CommandBase::oi->GetGamePad()->GetButton(F310::kYButton)) {
            CommandBase::roller->rollerBackward();
        } else {
            CommandBase::roller->rollerStop();
        }
        
        // Control turret Pan
        CommandBase::turret->Pan(-CommandBase::oi->GetGamePad()->GetX(F310::kLeftStick));  
        
        // Print gear state
        if (CommandBase::drive->GetState() == Drive::kHighGear) {
            SmartDashboard::GetInstance()->Log("High Gear", "Gear State");
        } else {
            SmartDashboard::GetInstance()->Log("Low Gear", "Gear State");
        }
        
        // Print ramp state
        if (CommandBase::giantFour->GetState() == GiantFour::kRampUp) {
            SmartDashboard::GetInstance()->Log("Ramp Up", "Ramp State");
        } else {
            SmartDashboard::GetInstance()->Log("Ramp Down", "Ramp State");
        }
        
        Scheduler::GetInstance()->Run();
    }
};

START_ROBOT_CLASS(CommandBasedRobot);

