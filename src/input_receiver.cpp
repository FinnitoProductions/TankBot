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
#include <functional>

InputReceiver::InputReceiver(int channel_gpio, std::function<double(double)> input_filter) {
   channelGPIO = channel_gpio;
   inputFilter = input_filter;

   gpioSetMode(channelGPIO, PI_INPUT);
   prevHighTick = gpioTick();

   /*
   * The function passed as the second argument is called every time the GPIO input changes from either low to high or 
   * high to low. If the GPIO changes from low to high (rise), the value of "level" will be 1; otherwise it will be 0.
   * "tick" represents the amount of time elapsed (in microseconds) since the first system boot. The third argument of the
   * gpioSetAlertFuncEx is passed back into the lambda for additional modification.
   */
   gpioSetAlertFuncEx(channelGPIO, [](int gpio, int level, unsigned int tick, void* userdata) {
      InputReceiver* ir = (InputReceiver*) userdata;

      if (level == 1) { // rise 
         ir->prevHighTick = tick;
      }
      else { // fall
         /*
         * The amount by which the distance in time between the rise tick and the fall tick deviates from the average distance (which 
         * represents an input of 0) is directly proportional to the output currently being sent through this channel.
         */
         double riseToFall = tick - ir->prevHighTick;
         double deviationFromAvg = riseToFall - ir->AVERAGE_RISE_TO_FALL;
         double result = deviationFromAvg / ir->MAX_DEVIATION_FROM_AVG; // map the value from [-500, 500] to [-1, 1]
         double resultConstrained = std::min(1.0, std::max(-1.0, result)); // constrain result to range between [-1, 1]

         ir->currentInput = ir->inputFilter(resultConstrained);

         // if (resultConstrained > 0.2 || resultConstrained < -0.2) {
         //    std::cout << gpio << " " << resultConstrained << std::endl;
         // }
      }
      
      // ir->prevTick = tick;
   }, this);
}

double InputReceiver::getCurrentInput() {
   return currentInput;
}