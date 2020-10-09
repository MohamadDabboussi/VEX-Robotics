#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor myMotor = motor(PORT1, ratio18_1, false);
controller Controller1 = controller(primary);
gyro myGyroA = gyro(Brain.ThreeWirePort.D);
line myLineTrackerH = line(Brain.ThreeWirePort.H);
bumper myBumperA = bumper(Brain.ThreeWirePort.A);
pot PotentiometerB = pot(Brain.ThreeWirePort.B);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}