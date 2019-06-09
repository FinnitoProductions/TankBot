/**
* Represents the drivetrain on a robot, with a set of motors on each side.
*
* @author Finn Frankis
* @since 6/2/19
*/

#include <subsystem.hpp>
#include <vector>
#include <digital_motor.hpp>

#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

extern double maxDigitalOutput; // the maximum output percent when the motors are being enabled as on/off

class Drivetrain : public Subsystem {
   public:
      void periodic();
      void setBothOutputs (double left_output, double right_output);
      static Drivetrain* getInstance();
   private:
      std::vector<DigitalMotor> leftMotors;
      std::vector<DigitalMotor> rightMotors;
      double leftOutput;
      double rightOutput;
      static Drivetrain* instance;
      Drivetrain();
};

#endif // DRIVETRAIN_H