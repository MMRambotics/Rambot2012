#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/ArcadeDrive.h"
#include "Commands/TankDrive.h"

class CommandBasedRobot : public IterativeRobot {
private:
    Command *autonomousCommand;
    Command *driveCommand;
    SendableChooser *driveStyle;
    
    bool previousTrigger;
    bool currentTrigger;
        
    virtual void RobotInit() {
        NetworkTable::Initialize();
        
        CommandBase::init();
        driveStyle = new SendableChooser();
        driveStyle->AddDefault("Arcade",new ArcadeDrive());
        driveStyle->AddObject("Tank",new TankDrive());
        SmartDashboard::GetInstance()->PutData("Drive Style Chooser", driveStyle);
        autonomousCommand = new ExampleCommand();
        
        previousTrigger = false;
    }
    
    virtual void AutonomousInit() {
        autonomousCommand->Start();
    }
    
    virtual void AutonomousPeriodic() {
        Scheduler::GetInstance()->Run();
    }
    
    virtual void TeleopInit() {
        autonomousCommand->Cancel();
        driveCommand =  (Command*) driveStyle->GetSelected();
        driveCommand->Start();
    }
    
    virtual void TeleopPeriodic() {
        Scheduler::GetInstance()->Run();
        
        currentTrigger = CommandBase::oi->GetRightStick()->GetTrigger();

        if (currentTrigger !=  previousTrigger && currentTrigger == false) {
            CommandBase::drive->SwitchGear();
        }

        if (CommandBase::oi->GetGamePad()->GetDPadX()!= 0.0) {
            CommandBase::conveyor->ConveyorStop();
        } else if (CommandBase::oi->GetGamePad()->GetDPadY()> 0.0) {
            CommandBase::conveyor->ConveyorUp();
        } else if (CommandBase::oi->GetGamePad()->GetDPadY() < 0.0) {
            CommandBase::conveyor->ConveyorDown();
        }
        CommandBase::turret->SetShooterSpeed(CommandBase::oi->GetGamePad()->GetY(F310::kRightStick));
        CommandBase::turret->Pan(CommandBase::oi->GetGamePad()->GetX(F310::kLeftStick));  
        previousTrigger = currentTrigger;
    }
};

START_ROBOT_CLASS(CommandBasedRobot);

