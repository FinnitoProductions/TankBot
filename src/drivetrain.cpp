/**
* Defines methods for the drivetrain on a robot, with a set of motors on each side.
*
* @author Finn Frankis
* @version 6/2/19
*/

#include <drivetrain.hpp>
#include <iostream>

Drivetrain::Drivetrain (std::vector<Motor> left_motors, std::vector<Motor> right_motors) {
   leftMotors = left_motors;
   rightMotors = right_motors;
}

void Drivetrain::periodic() {
   char x;
   std::cin >> x;

   if (x == FORWARD_CHAR) {
      setBothOutputs(MAX_DIGITAL_OUTPUT, MAX_DIGITAL_OUTPUT);
   }
   else if (x == REVERSE_CHAR) {
      setBothOutputs(-MAX_DIGITAL_OUTPUT, -MAX_DIGITAL_OUTPUT);
   }
   else if (x == LEFT_CHAR) {
      setBothOutputs(-MAX_DIGITAL_OUTPUT, MAX_DIGITAL_OUTPUT);
   }
   else if (x == RIGHT_CHAR) {
      setBothOutputs(MAX_DIGITAL_OUTPUT, -MAX_DIGITAL_OUTPUT);
   }
}

void Drivetrain::setBothOutputs (double left_output, double right_output) {
   for (Motor m : leftMotors) {
      m.setOutput(left_output);
   }
   for (Motor m : rightMotors) {
      m.setOutput(right_output);
   }
}