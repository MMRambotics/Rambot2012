#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
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
    SendableChooser *autoMode;
    bool previousShiftTrigger;
    bool currentShiftTrigger;
    bool previousRampTrigger;
    bool currentRampTrigger;
    bool isFourState;
    int fourStateIndex;
    Command *rampUp;
    Command *rampDown;
public:    
    CommandBasedRobot() {
        rampUp = new UndeployRamp();
        rampDown = new DeployRamp();
        compressor = new Compressor(PRESSURE_SWITCH_PORT, COMPRESSOR_RELAY_PORT);
        compressor->Start();

        CommandBase::init();
        driveStyle = new SendableChooser();
        autoMode = new SendableChooser();
        driveStyle->AddDefault("Arcade",new ArcadeDrive());
        driveStyle->AddObject("Tank",new TankDrive());
        
        previousShiftTrigger = false;
        previousRampTrigger = false;
        isFourState = false;
        fourStateIndex = 0;
     
    }
    virtual void RobotInit() {
        NetworkTable::Initialize();
        SmartDashboard::GetInstance()->PutData("Drive Style Chooser", driveStyle);
        SmartDashboard::GetInstance()->PutData("Auto Mode Chooser", autoMode);
    }
    
    virtual void AutonomousInit() {

    }
    
    virtual void AutonomousPeriodic() {
    }
    
    virtual void TeleopInit() {
        driveCommand =  (Command*) driveStyle->GetSelected();
        CommandBase::turret->Reset();
        CommandBase::turret->Start();
    }
    
    virtual void TeleopPeriodic() {
        
        
        currentShiftTrigger = CommandBase::oi->GetLeftStick()->GetRawButton(1);
        if (currentShiftTrigger !=  previousShiftTrigger && currentShiftTrigger == false) {
            CommandBase::drive->SwitchGear();
        }
        
        //currentRampTrigger = CommandBase::oi->GetLeftStick()->GetRawButton(3);
        /*
        if (currentRampTrigger != previousRampTrigger && currentRampTrigger == false) {
            if (CommandBase::giantFour->GetState() == GiantFour::kRampDown) {
                rampDown->Start();
            }
            else {
                rampUp->Start();  
            }
        }*/

        /*if (CommandBase::oi->GetGamePad()->GetDPadX()!= 0.0) {
            CommandBase::roller->rollerStop();
        } else if (CommandBase::oi->GetGamePad()->GetDPadY()> 0.0) {
            CommandBase::roller->rollerForward();
        } else if (CommandBase::oi->GetGamePad()->GetDPadY() < 0.0) {
            CommandBase::roller->rollerBackward();
        }*/
        
        if (CommandBase::oi->GetGamePad()->GetDPadY() > 0.0) {
            CommandBase::conveyor->ConveyorUp();
        } else if (CommandBase::oi->GetGamePad()->GetDPadY() < 0.0) {
            CommandBase::conveyor->ConveyorDown();
        } else {
            CommandBase::conveyor->ConveyorStop();
        }
        
        if (CommandBase::oi->GetGamePad()->GetButton(F310::kAButton)) {
            CommandBase::roller->rollerForward();
        } else if (CommandBase::oi->GetGamePad()->GetButton(F310::kYButton)) {
            CommandBase::roller->rollerBackward();
        } else {
            CommandBase::roller->rollerStop();
        }

        CommandBase::turret->Pan(-CommandBase::oi->GetGamePad()->GetX(F310::kLeftStick));  
        
        previousShiftTrigger = currentShiftTrigger;
        previousRampTrigger = currentRampTrigger;
        
        if (CommandBase::drive->GetState() == Drive::kHighGear) {
            SmartDashboard::GetInstance()->Log("High Gear", "Gear State");
        } else {
            SmartDashboard::GetInstance()->Log("Low Gear", "Gear State");
        }
        if (CommandBase::giantFour->GetState() == GiantFour::kRampUp) {
            SmartDashboard::GetInstance()->Log("Ramp Up", "Ramp State");
        } else {
            SmartDashboard::GetInstance()->Log("Ramp Down", "Ramp State");
        }
        Scheduler::GetInstance()->Run();
    }
};

START_ROBOT_CLASS(CommandBasedRobot);

