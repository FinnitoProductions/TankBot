/**
* Contains the generalized information for a robot subsystem.
*
* @author Finn Frankis
* @since 6/2/19
*/

#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

class Subsystem {
   public:
      Subsystem();
      virtual void periodic() {}
};

#endif // SUBSYSTEM_H