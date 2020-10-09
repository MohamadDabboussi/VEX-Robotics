/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Moham                                            */
/*    Created:      Wed Dec 04 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// myMotor              motor         1               
// Controller1          controller                    
// myGyroA              gyro          D               
// myLineTrackerH       line          H               
// myBumperA            bumper        A               
// PotentiometerB       pot           B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void printhello();

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // motors
  // myMotor.setVelocity(30, rpm);
  // myMotor.spin(forward);
  // int nbOfTurns;
  // double position;
  // double PI=3.14159265;
  // while (1) {
  //   nbOfTurns = myMotor.position(turns);
  //   position=nbOfTurns*PI*10;//in cm
  //   Brain.Screen.print(position);
  //   Brain.Screen.newLine();
  //   wait(1,seconds);
  // }

  // controller
  // int i;
  // while(true){
  //   i=Controller1.Axis3.position(percent);//from -100 to 100
  //   Brain.Screen.clearScreen();
  //   Brain.Screen.setCursor(1,1);
  //   Brain.Screen.print(i);
  //   wait(1, seconds);

  // }
  // Controller1.ButtonL1.pressed(printhello);
  // while (true) {
  //   if (Controller1.ButtonUp.pressing()) {
  //     Brain.Screen.print("pressing");
  //     break;

  //   }
  // }

  // gyro
  // myGyroA.setHeading(0,degrees);
  // while(true){
  //   Brain.Screen.print(myGyroA.heading()*1.511);
  //   Brain.Screen.newLine();
  //   wait(1,seconds);
  // }

  // linetracker
  // while (true) {
  //   if (myLineTrackerH.reflectivity() < 30) {
  //     Brain.Screen.print("dark");
  //   } else {
  //     Brain.Screen.print("light");
  //   }
  //   Brain.Screen.newLine();
  //   wait(1, seconds);
  // }

  //bumper
  myBumperA.released(printhello);

  //potentiometer
  int a;
  while(true){
    a=PotentiometerB.angle(degrees);
    Brain.Screen.print(a);
    Brain.Screen.newLine();
    wait(1,seconds);
  }
  


}

void printhello(){
  int i=0;
  while(true){
    i++;
    Brain.Screen.print(i);
    Brain.Screen.newLine();
    wait(1,seconds);
  }
}
