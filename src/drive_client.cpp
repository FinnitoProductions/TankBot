/**
* The client file containing the main() method to execute all robot operations.
* 
* @author Finn Frankis
* @version 6/1/19
*/

#include <pigpio.h>
#include <iostream>
#include <digital_motor.hpp>
#include <robot_map.hpp>
#include <scheduler.hpp>
#include <chrono>
#include <thread>
#include <input_receiver.hpp>
#include <math.h>
#include <drivetrain.hpp>

int main() {
   gpioInitialise(); // must be called in any pigpio program before interfacing with GPIO
   std::cout << "GPIO initialized." << std::endl;

   Drivetrain* d = Drivetrain::getInstance();

   for (DigitalMotor m : d->getLeftMotors()) {
      m.playSound(6000);
   }

   while (true) {
      Scheduler::getInstance()->run();
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
   }

   
   gpioTerminate(); 
}