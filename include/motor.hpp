/**
 * Represents a single motor using an L298N H-bridge.
 * 
 * @author Finn Frankis
 * @since 6/1/19
*/

class Motor {
   const int FORWARD_PIN;
   const int REVERSE_PIN;
   const int ENABLE_PIN;
   
   const int PWM_OUTPUT_RANGE = 255; // the distance between minimum and maximum possible PWM output

   public:
      Motor(int forward_pin, int reverse_pin, int enable_pin);
      void setOutput(double output);
};