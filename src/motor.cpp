/**
 * CPP file for a single motor using an L298N H-bridge.
 * 
 * @author Finn Frankis
 * @since 6/1/19
*/

#include <motor.h>
#include <pigpio.h>

const int PWM_OUTPUT_RANGE = 255; // the distance between minimum and maximum possible PWM output

/**
* Constructs a new motor object.
*
* @param forward_pin the GPIO pin through which forward output will be enabled on the H-bridge
* @param backward_pin the GPIO pin through which backward output will be enabled on the H-bridge
* @param reverse_pin the GPIO pin through which the magnitude of the output will be specified to the H-bridge (via PWM)
*/
Motor::Motor(int forward_pin, int reverse_pin, int enable_pin) : FORWARD_PIN(forward_pin), REVERSE_PIN(reverse_pin), ENABLE_PIN(enable_pin) {
   gpioSetMode(FORWARD_PIN, PI_OUTPUT);
   gpioSetMode(REVERSE_PIN, PI_OUTPUT);
   gpioSetMode(ENABLE_PIN, PI_OUTPUT);
}

/**
* Drives the motor forward at a given speed.
*
* @param output the output at which to drive the motor [-1, 1]
*/
void Motor::setOutput (double output) {
   if (output > 0) {
      gpioWrite(FORWARD_PIN, PI_ON);
      gpioWrite(REVERSE_PIN, PI_OFF);
      gpioPWM(ENABLE_PIN, output * PWM_OUTPUT_RANGE);
   } else if (output < 0) {
      gpioWrite(FORWARD_PIN, PI_OFF);
      gpioWrite (REVERSE_PIN, PI_ON);
      gpioPWM(ENABLE_PIN, -output * PWM_OUTPUT_RANGE);
   }
   else {
      gpioWrite(FORWARD_PIN, PI_OFF);
      gpioWrite(REVERSE_PIN, PI_OFF);
   }
}