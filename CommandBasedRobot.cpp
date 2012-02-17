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
    
    virtual void RobotInit() {
        //NetworkTable::Initialize();
        
        CommandBase::init();
        driveStyle = new SendableChooser();
        driveStyle->AddDefault("Arcade",new ArcadeDrive());
        driveStyle->AddObject("Tank",new TankDrive());
        SmartDashboard::GetInstance()->PutData("Drive Style Chooser", driveStyle);
        autonomousCommand = new ExampleCommand();
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

        if (CommandBase::oi->GetGamePad()->GetDPadX()!= 0.0) {
            CommandBase::conveyor->ConveyorStop();
        } else if (CommandBase::oi->GetGamePad()->GetDPadY()< 0.0) {
            CommandBase::conveyor->ConveyorUp();
        } else if (CommandBase::oi->GetGamePad()->GetDPadY() > 0.0) {
            CommandBase::conveyor->ConveyorDown();
        }
        CommandBase::turret->SetShooterSpeed(CommandBase::oi->GetGamePad()->GetY(F310::kRightStick));
        CommandBase::turret->Pan(CommandBase::oi->GetGamePad()->GetY(F310::kLeftStick));
    }
};

START_ROBOT_CLASS(CommandBasedRobot);

