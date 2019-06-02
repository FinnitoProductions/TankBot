/**
* Defines methods for the drivetrain on a robot, with a set of motors on each side.
*
* @author Finn Frankis
* @version 6/2/19
*/

#include <drivetrain.hpp>
#include <iostream>

Drivetrain::Drivetrain(std::vector<DigitalMotor> left_motors, std::vector<DigitalMotor> right_motors) {
   leftMotors = left_motors;
   rightMotors = right_motors;
}

void Drivetrain::periodic() {
   char x;
   std::cin >> x;

   if (x == FORWARD_CHAR) {
      std::cout << "forward" << std::endl;
      setBothOutputs(MAX_DIGITAL_OUTPUT, MAX_DIGITAL_OUTPUT);
   }
   else if (x == REVERSE_CHAR) {
      std::cout << "reverse" << std::endl;
      setBothOutputs(-MAX_DIGITAL_OUTPUT, -MAX_DIGITAL_OUTPUT);
   }
   else if (x == LEFT_CHAR) {
      std::cout << "left" << std::endl;
      setBothOutputs(-MAX_DIGITAL_OUTPUT, MAX_DIGITAL_OUTPUT);
   }
   else if (x == RIGHT_CHAR) {
      std::cout << "right" << std::endl;
      setBothOutputs(MAX_DIGITAL_OUTPUT, -MAX_DIGITAL_OUTPUT);
   }
   else if (x == STOP_CHAR) {
      std::cout << "stop" << std::endl;
      setBothOutputs(0, 0);
   }
}

void Drivetrain::setBothOutputs (double left_output, double right_output) {
   for (DigitalMotor m : leftMotors) {
      m.setOutput(left_output);
   }
   for (DigitalMotor m : rightMotors) {
      m.setOutput(right_output);
   }
}