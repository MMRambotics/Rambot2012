#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define ROLLER_SPEED 0.5
#define RAMP_LOCK_WAIT_TIME 1.0
#define CONVEYOR_SPEED 0.5
#define TOLERANCE 100

// PID Constants for Driving Straight
const static float DRIVE_STRAIGHT_P = 0.075;
const static float DRIVE_STRAIGHT_I = 0.0;
const static float DRIVE_STRAIGHT_D = 0.0;

// PID Constant for Turret
const static float TURRET_P_RIGHT = 0.0005;
const static float TURRET_I_RIGHT = 0.0001;
const static float TURRET_D_RIGHT = 0.0004;
const static float TURRET_P_LEFT = 0.0005;
const static float TURRET_I_LEFT = 0.0001;
const static float TURRET_D_LEFT = 0.0004;

#endif
