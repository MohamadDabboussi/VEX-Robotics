#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftFrontMotorDrive = motor(PORT1, ratio18_1, false);
motor rightFrontMotorDrive = motor(PORT7, ratio18_1, false);
motor leftBackMotorDrive = motor(PORT15, ratio18_1, false);
motor rightBackMotorDrive = motor(PORT20, ratio18_1, false);
controller Controller1 = controller(primary);
motor leftDownCraneMotor = motor(PORT3, ratio18_1, false);
motor leftUpCraneMotor = motor(PORT12, ratio18_1, false);
motor rightDownCraneMotor = motor(PORT9, ratio18_1, true);
motor rightUpCraneMotor = motor(PORT18, ratio18_1, true);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}