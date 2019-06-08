/**
* Periodically updates the states of all subsystems required for robot control.
*
* @author Finn Frankis
* @since 6/7/19 
*/

#include <vector>
#include <subsystem.hpp>

#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler {
   private:
      static Scheduler* instance;
      Scheduler();
      std::vector<Subsystem*> subsystems;
   public:
      static Scheduler* getInstance();
      void run();
      void add(Subsystem* s);
};

#endif // SCHEDULER_H