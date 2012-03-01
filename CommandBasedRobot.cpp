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
    
    bool previousShiftTrigger;
    bool currentShiftTrigger;
    bool previousRampTrigger;
    bool currentRampTrigger;
        
    virtual void RobotInit() {
        NetworkTable::Initialize();
        
        CommandBase::init();
        driveStyle = new SendableChooser();
        driveStyle->AddDefault("Arcade",new ArcadeDrive());
        driveStyle->AddObject("Tank",new TankDrive());
        SmartDashboard::GetInstance()->PutData("Drive Style Chooser", driveStyle);
        autonomousCommand = new KinectTankDrive();
        
        previousShiftTrigger = false;
        previousRampTrigger = false;
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
        
        currentShiftTrigger = CommandBase::oi->GetRightStick()->GetRawButton(3);
        if (currentShiftTrigger !=  previousShiftTrigger && currentShiftTrigger == false) {
            CommandBase::drive->SwitchGear();
        }
        
        currentRampTrigger = CommandBase::oi->GetLeftStick()->GetRawButton(3);
        if (currentRampTrigger != previousRampTrigger && currentRampTrigger == false) {
            if (CommandBase::giantFour->GetState() == GiantFour::kRampDown) CommandBase::giantFour->RampUp();
            else CommandBase::giantFour->RampDown();
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
        
        previousShiftTrigger = currentShiftTrigger;
        previousRampTrigger = currentRampTrigger;
    }
};

START_ROBOT_CLASS(CommandBasedRobot);

