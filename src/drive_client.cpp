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
#include <math.h>

static const int NUM_CH3_PRESSES_TO_TERMINATE = 3;
int main() {
   std::cout << "Testing driving!" << std::endl;
   gpioInitialise(); // must be called in any pigpio program before interfacing with GPIO

   Drivetrain drivetrain({DigitalMotor(FORWARD_LEFT_DRIVE, REVERSE_LEFT_DRIVE, ENABLE_LEFT_DRIVE)}, 
                         {DigitalMotor(FORWARD_RIGHT_DRIVE, REVERSE_RIGHT_DRIVE, ENABLE_RIGHT_DRIVE)});

   InputReceiver irTrigger(CH2_TRIGGER_INPUT);
   InputReceiver irWheel(CH1_WHEEL_INPUT);

   double prevCh3 = 0;
   double numPressesCh3 = 0;
   InputReceiver ir3(CH3_INPUT, [&prevCh3, &numPressesCh3](double ch3) {
      if (numPressesCh3 > NUM_CH3_PRESSES_TO_TERMINATE) {
         std::cout << "Terminating program." << std::endl;
         exit(0);
      }
      if (prevCh3 != 0 && std::copysign(1, prevCh3) != std::copysign(1, ch3)) { // if the channel 3 value changed signs, it was pressed
         std::cout << "Channel 3 pressed." << std::endl;
         numPressesCh3++;
      }

      prevCh3 = ch3;
      return ch3;
   });

    while (true) {	   
      drivetrain.setBothOutputs(ir3.getCurrentInput() * irTrigger.getCurrentInput() + irWheel.getCurrentInput(), ir3.getCurrentInput() * irTrigger.getCurrentInput() - irWheel.getCurrentInput());
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
   }

   
   gpioTerminate(); 
}