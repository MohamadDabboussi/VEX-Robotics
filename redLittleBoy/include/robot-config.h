using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftFrontMotorDrive;
extern motor rightFrontMotorDrive;
extern motor leftBackMotorDrive;
extern motor rightBackMotorDrive;
extern controller Controller1;
extern motor leftDownCraneMotor;
extern motor leftUpCraneMotor;
extern motor rightDownCraneMotor;
extern motor rightUpCraneMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );