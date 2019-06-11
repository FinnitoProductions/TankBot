/**
 * Defines methods for a single motor using an L298N H-bridge.
 * 
 * @author Finn Frankis
 * @since 6/1/19
*/

#include <digital_motor.hpp>
#include <iostream>
#include <thread>
#include <chrono>


/**
* Constructs a new motor object.
* 
* @param forward_pin the GPIO pin through which forward output will be enabled on the H-bridge
* @param backward_pin the GPIO pin through which backward output will be enabled on the H-bridge
* @param reverse_pin the GPIO pin through which the magnitude of the output will be specified to the H-bridge (via PWM)
*/
DigitalMotor::DigitalMotor(const int forward_pin, const int reverse_pin, const int enable_pin) : FORWARD_PIN(forward_pin), REVERSE_PIN(reverse_pin), ENABLE_PIN(enable_pin) {
   gpioSetMode(FORWARD_PIN, PI_OUTPUT);
   gpioSetMode(REVERSE_PIN, PI_OUTPUT); 
   gpioSetMode(ENABLE_PIN, PI_OUTPUT);
} 

/**
* Drives the motor forward at a given speed.
*
* @param output the output at which to drive the motor [-1, 1]
*/
void DigitalMotor::setOutput (double output) {
   output = std::max(-1.0, std::min(1.0, output)); // constrain to range of [-1, 1]
   if (output > OUTPUT_DEADBAND) {
      gpioWrite(FORWARD_PIN, PI_ON);
      gpioWrite(REVERSE_PIN, PI_OFF);
      gpioPWM(ENABLE_PIN, output * PWM_OUTPUT_RANGE);
   } else if (output < -OUTPUT_DEADBAND) {
      gpioWrite(FORWARD_PIN, PI_OFF);
      gpioWrite (REVERSE_PIN, PI_ON);
      gpioPWM(ENABLE_PIN, -output * PWM_OUTPUT_RANGE);
   }
   else {
      gpioWrite(FORWARD_PIN, PI_OFF);
      gpioWrite(REVERSE_PIN, PI_OFF);
      gpioPWM(ENABLE_PIN, PI_OFF);
   }
}