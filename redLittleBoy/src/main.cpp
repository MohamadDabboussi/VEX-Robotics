/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftFrontMotorDrive  motor         1               
// rightFrontMotorDrive motor         7               
// leftBackMotorDrive   motor         15              
// rightBackMotorDrive  motor         20              
// Controller1          controller                    
// leftDownCraneMotor   motor         3               
// leftUpCraneMotor     motor         12              
// rightDownCraneMotor  motor         9               
// rightUpCraneMotor    motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

//methods declaration:
void moveRobot(int LSpeed, int RSpeed);
void goUpUntil();
void moveCrane(int speed);


// define your global instances of motors and other devices here
int height;
int craneSpeedPercent;


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  height=0;
  craneSpeedPercent=50;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  int leftJoysticPosition,rightJoysticPosition;
  Controller1.ButtonB.pressed(goUpUntil);
  Controller1.ButtonA.pressed(goUpUntil);
  Controller1.ButtonX.pressed(goUpUntil);
  Controller1.ButtonY.pressed(goUpUntil);

  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    leftJoysticPosition=Controller1.Axis3.position(percent);
		rightJoysticPosition =Controller1.Axis2.position(percent);

    
		if(abs(leftJoysticPosition) < 10){leftJoysticPosition = 0;}
		if(abs(rightJoysticPosition) < 10){rightJoysticPosition = 0;}
		if(leftJoysticPosition*rightJoysticPosition < 0){leftJoysticPosition = 0.4*leftJoysticPosition;rightJoysticPosition = 0.4*rightJoysticPosition;}
    else{leftJoysticPosition=0.8*leftJoysticPosition;rightJoysticPosition=0.8*rightJoysticPosition;}
    Brain.Screen.print(leftJoysticPosition);
    Brain.Screen.newLine();
		moveRobot(leftJoysticPosition,rightJoysticPosition);

    if(Controller1.ButtonB.pressing())height=2;
    if(Controller1.ButtonA.pressing())height=4;
    if(Controller1.ButtonX.pressing())height=6;
    if(Controller1.ButtonY.pressing())height=0;
  

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

void moveRobot(int LSpeed, int RSpeed){
  leftFrontMotorDrive.setVelocity(LSpeed,percent);
  leftFrontMotorDrive.spin(forward);
  leftBackMotorDrive.setVelocity(LSpeed,percent);
  leftBackMotorDrive.spin(forward);

  rightFrontMotorDrive.setVelocity(RSpeed,percent);
  rightFrontMotorDrive.spin(forward);
  rightBackMotorDrive.setVelocity(RSpeed,percent);
  rightBackMotorDrive.spin(forward);
    
}

void goUpUntil(){
  int nbOfTurns;
  nbOfTurns = leftUpCraneMotor.position(turns);
  moveCrane(craneSpeedPercent);


}

void moveCrane(int speed){
  leftUpCraneMotor.setVelocity(speed,percent);
  leftUpCraneMotor.spin(forward);
  leftDownCraneMotor.setVelocity(speed,percent);
  leftDownCraneMotor.spin(forward);
  rightUpCraneMotor.setVelocity(speed,percent);
  rightUpCraneMotor.spin(forward);
  rightDownCraneMotor.setVelocity(speed,percent);
  rightDownCraneMotor.spin(forward);
}