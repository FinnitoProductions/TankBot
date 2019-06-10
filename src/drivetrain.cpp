/**
* Defines methods for the drivetrain on a robot, with a set of motors on each side.
*
* @author Finn Frankis
* @version 6/2/19
*/

#include <drivetrain.hpp>
#include <iostream>
#include <algorithm>
#include <robot_map.hpp>
#include <input_devices.hpp>

double maxDigitalOutput = 1;

Drivetrain* Drivetrain::instance = 0;

Drivetrain::Drivetrain() {
   leftMotors = {DigitalMotor(FORWARD_LEFT_DRIVE, REVERSE_LEFT_DRIVE, ENABLE_LEFT_DRIVE)};
   rightMotors = {DigitalMotor(FORWARD_RIGHT_DRIVE, REVERSE_RIGHT_DRIVE, ENABLE_RIGHT_DRIVE)};
}

void Drivetrain::periodic() {
   InputDevices* id = InputDevices::getInstance();
   setBothOutputs(id->getIrTrigger().getCurrentInput() + id->getIrWheel().getCurrentInput(), id->getIrTrigger().getCurrentInput() - id->getIrWheel().getCurrentInput());
}

void Drivetrain::setBothOutputs (double left_output, double right_output) {
   for (DigitalMotor m : leftMotors) {
      m.setOutput(left_output);
   }
   for (DigitalMotor m : rightMotors) {
      m.setOutput(right_output);
   }
}

Drivetrain* Drivetrain::getInstance() {
   if (instance == nullptr) {
      instance = new Drivetrain();
   }

   return instance;
}

std::vector<DigitalMotor> Drivetrain::getLeftMotors() { return leftMotors; }     
std::vector<DigitalMotor> Drivetrain::getRightMotors() { return rightMotors; }