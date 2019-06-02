/**
* The client file containing the main() method to execute all robot operations.
* 
* @author Finn Frankis
* @version 6/1/19
*/

#include <pigpio.h>
#include <iostream>
#include <motor.h>
#include <robot_map.h>

int main() {
   std::cout << "Testing driving!" << std::endl;
   gpioInitialise(); // must be called in any pigpio program before interfacing with GPIO

   Motor leftMotor(FORWARD_LEFT_DRIVE, REVERSE_LEFT_DRIVE, ENABLE_LEFT_DRIVE);
   Motor rightMotor(FORWARD_RIGHT_DRIVE, REVERSE_RIGHT_DRIVE, ENABLE_RIGHT_DRIVE);
   
   gpioTerminate();
}