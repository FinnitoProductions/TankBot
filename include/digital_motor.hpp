/**
 * Represents a single motor using an L298N H-bridge.
 * 
 * @author Finn Frankis
 * @since 6/1/19
*/

#ifndef DIGITALMOTOR_H
#define DIGITALMOTOR_H

#include <pigpio.h>

class DigitalMotor {
   int FORWARD_PIN;
   int REVERSE_PIN;
   int ENABLE_PIN;
   
   int PWM_OUTPUT_RANGE = 255; // the distance between minimum and maximum possible PWM output

   public:
      DigitalMotor(int forward_pin, int reverse_pin, int enable_pin);
      void setOutput(double output);
};

#endif // DIGITAL_MOTOR_H