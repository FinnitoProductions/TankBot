/**
* Takes in and parses input sent over a GPIO pin from a given channel of an FS-GR3E receiver.
*
* @author Finn Frankis
* @since 6/3/19
*/

#ifndef INPUTRECEIVER_H
#define INPUTRECEIVER_H

class InputReceiver {
   public:
      InputReceiver (int channelGPIO);
      double getCurrentInput();
   private:
      double channelGPIO;
      int prevHighTick;
      const double AVERAGE_RISE_TO_FALL = 1500.0; // the average distance in time (microseconds) between the rise and fall
      const double MAX_DEVIATION_FROM_AVG = 500.0; // the range by which a given rise to fall distance can deviate from the average
      double currentInput;
};

#endif // INPUTRECEIVER_H