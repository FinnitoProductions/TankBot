/**
* Represents the drivetrain on a robot, with a set of motors on each side.
*
* @author Finn Frankis
* @version 6/2/19
*/

#include <subsystem.hpp>
#include <vector>
#include <digital_motor.hpp>

const char FORWARD_CHAR = 'W';
const char REVERSE_CHAR = 'S';
const char LEFT_CHAR = 'A';
const char RIGHT_CHAR = 'D';
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