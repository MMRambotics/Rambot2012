#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/ArcadeDrive.h"
#include "Commands/TankDrive.h"
#include "Commands/KinectTankDrive.h"

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
        autonomousCommand = new KinectTankDrive();
        
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
        CommandBase::turret->Reset();
        CommandBase::turret->Start();
    }
    
    virtual void TeleopPeriodic() {
        Scheduler::GetInstance()->Run();
        
        currentTrigger = CommandBase::oi->GetRightStick()->GetTrigger();

        if (currentTrigger !=  previousTrigger && currentTrigger == false) {
            CommandBase::drive->SwitchGear();
        }

        if (CommandBase::oi->GetGamePad()->GetDPadX()!= 0.0) {
            CommandBase::roller->rollerStop();
        } else if (CommandBase::oi->GetGamePad()->GetDPadY()> 0.0) {
            CommandBase::roller->rollerForward();
        } else if (CommandBase::oi->GetGamePad()->GetDPadY() < 0.0) {
            CommandBase::roller->rollerBackward();
        }
        //CommandBase::turret->Process();
        //CommandBase::turret->SetShooterSpeed(0.0);
        CommandBase::turret->Pan(CommandBase::oi->GetGamePad()->GetX(F310::kLeftStick));  
        previousTrigger = currentTrigger;
    }
};

START_ROBOT_CLASS(CommandBasedRobot);

