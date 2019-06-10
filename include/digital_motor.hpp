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
   
   static const int PWM_OUTPUT_RANGE = 255; // the distance between minimum and maximum possible PWM output
   static constexpr double OUTPUT_DEADBAND = 0.25; // the range of output from zero for which motor output is mere noise
   static constexpr double SOUND_OUTPUT = 0.15; // the output that will be played to make a sound from the robot

   public:
      DigitalMotor(int forward_pin, int reverse_pin, int enable_pin);
      void setOutput(double output);
      void playSound(int milliseconds);
};

#endif // DIGITAL_MOTOR_H