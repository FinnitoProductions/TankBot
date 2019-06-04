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
#include <drivetrain.hpp>
#include <chrono>
#include <thread>
#include <input_receiver.hpp>

int main() {
   std::cout << "Testing driving!" << std::endl;
   gpioInitialise(); // must be called in any pigpio program before interfacing with GPIO

   Drivetrain drivetrain({DigitalMotor(FORWARD_LEFT_DRIVE, REVERSE_LEFT_DRIVE, ENABLE_LEFT_DRIVE)}, 
                         {DigitalMotor(FORWARD_RIGHT_DRIVE, REVERSE_RIGHT_DRIVE, ENABLE_RIGHT_DRIVE)});

   InputReceiver irTrigger(CH2_TRIGGER_INPUT);
   InputReceiver irWheel(CH1_WHEEL_INPUT);
   InputReceiver ir3(CH3_INPUT, [](float ch3){exit(0); return ch3;});

   while (true) {
      // drivetrain.periodic();
      drivetrain.setBothOutputs(ir3.getCurrentInput() * irTrigger.getCurrentInput() + irWheel.getCurrentInput(), ir3.getCurrentInput() * irTrigger.getCurrentInput() - irWheel.getCurrentInput());
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
   }

   
   gpioTerminate(); 
}