/**
* Represents the drivetrain on a robot, with a set of motors on each side.
*
* @author Finn Frankis
* @version 6/2/19
*/

#include <subsystem.hpp>
#include <vector>
#include <digital_motor.hpp>

#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

const char FORWARD_CHAR = 'w';
const char REVERSE_CHAR = 's';
const char LEFT_CHAR = 'a';
const char RIGHT_CHAR = 'd';
const char STOP_CHAR = 'o';
const char MAX_DIGITAL_OUTPUT = 1; // the maximum output percent when the motors are being enabled as on/off

class Drivetrain : public Subsystem {
   public:
      Drivetrain(std::vector<DigitalMotor> left_motors, std::vector<DigitalMotor> right_motors);
      void periodic();
      void setBothOutputs (double left_output, double right_output);
   private:
      std::vector<DigitalMotor> leftMotors;
      std::vector<DigitalMotor> rightMotors;
};

#endif // DRIVETRAIN_H