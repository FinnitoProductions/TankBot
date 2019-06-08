/**
* Defines methods for all the devices required for receiving user input.
* 
* @author Finn Frankis
* @since 6/7/19
*/

#include <input_devices.hpp>
#include <robot_map.hpp>
#include <iostream>
#include <math.h>

InputDevices* InputDevices::instance = 0;

InputDevices::InputDevices() : irWheel(CH1_WHEEL_INPUT), 
                               irTrigger(CH2_TRIGGER_INPUT), 
                               ir3(CH3_INPUT, 
                                 [this](double ch3) {
                                    if (numPressesCh3 > NUM_CH3_PRESSES_TO_TERMINATE) {
                                          std::cout << "Terminating program." << std::endl;
                                          exit(0);
                                       }
                                       if (prevCh3 != 0 && copysign(1, prevCh3) != copysign(1, ch3)) { // if the channel 3 value changed signs, it was pressed
                                          std::cout << "Channel 3 pressed." << std::endl;
                                          numPressesCh3++;
                                       }

                                       prevCh3 = ch3;
                                       return ch3;
                                    }) 
{
}

InputReceiver InputDevices::getIrTrigger() { return irTrigger; }
InputReceiver InputDevices::getIrWheel() { return irWheel; }
InputReceiver InputDevices::getIr3() { return ir3; }