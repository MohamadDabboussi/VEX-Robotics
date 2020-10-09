using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor myMotor;
extern controller Controller1;
extern gyro myGyroA;
extern line myLineTrackerH;
extern bumper myBumperA;
extern pot PotentiometerB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );