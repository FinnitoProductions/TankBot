/**
* Defines methods for a class to parse input sent over a GPIO pin from a given channel of an FS-GR3E receiver.
*
* @author Finn Frankis
* @since 6/3/19
*/

#include <input_receiver.hpp>
#include <pigpio.h>
#include <iostream>
#include <tgmath.h>

InputReceiver::InputReceiver(int channel_gpio) {
   channelGPIO = channel_gpio;

   gpioSetMode(channelGPIO, PI_INPUT);
   prevHighTick = gpioTick();

   gpioSetAlertFuncEx(channelGPIO, [](int gpio, int level, unsigned int tick, void* userdata) {
      InputReceiver* ir = (InputReceiver*) userdata;

      if (level == 1) { // rise 
         ir->prevHighTick = tick;
      }
      else { // fall
         double riseToFall = tick - ir->prevHighTick;
         double deviationFromAvg = riseToFall - ir->AVERAGE_RISE_TO_FALL;
         double resultUnfiltered = deviationFromAvg / ir->MAX_DEVIATION_FROM_AVG;
         double resultFiltered = std::min(1.0, std::max(-1.0, resultUnfiltered)); // constrain result to range between [-1, 1]

         ir->currentInput = resultFiltered;
      }

      // std::cout << gpio << " " << level << " " << ir->prevTick << " " << (tick - ir->prevTick) << std::endl;
      // ir->prevTick = tick;
   }, this);
}