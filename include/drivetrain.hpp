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

static const char FORWARD_CHAR = 'w';
static const char REVERSE_CHAR = 's';
static const char LEFT_CHAR = 'a';
static const char RIGHT_CHAR = 'd';
static const char SLOW_DOWN_CHAR = 'l';
static const char SPEED_UP_CHAR = 'u';
static const char STOP_CHAR = 'o';

static const double SLOW_DOWN_RATE = 0.8;

extern double maxDigitalOutput; // the maximum output percent when the motors are being enabled as on/off

class Drivetrain : public Subsystem {
   public:
      Drivetrain(std::vector<DigitalMotor> left_motors, std::vector<DigitalMotor> right_motors);
      void periodic();
      void setBothOutputs (double left_output, double right_output);
   private:
      std::vector<DigitalMotor> leftMotors;
      std::vector<DigitalMotor> rightMotors;
      double leftOutput;
      double rightOutput;
};

#endif // DRIVETRAIN_H