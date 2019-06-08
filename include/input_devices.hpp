/**
* Stores all the devices required for receiving user input.
* 
* @author Finn Frankis
* @since 6/7/19
*/

#include <input_receiver.hpp>
#include <robot_map.hpp>

class InputDevices {
   private:
      const int CH1_WHEEL_INPUT = 23;
      const int CH2_TRIGGER_INPUT = 15;
      const int CH3_INPUT = 18; 

      static InputDevices* instance;
      InputDevices();
      InputReceiver irTrigger;
      InputReceiver irWheel;
      InputReceiver ir3;
      static const int NUM_CH3_PRESSES_TO_TERMINATE = 3;

      double prevCh3 = 0;
      double numPressesCh3 = 0;
   public:
      static InputDevices* getInstance();
      InputReceiver getIrTrigger();
      InputReceiver getIrWheel();
      InputReceiver getIr3();
};