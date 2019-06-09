/**
* Defines method to update the states of all subsystems required for robot control.
*
* @author Finn Frankis
* @since 6/7/19 
*/

#include <scheduler.hpp>

Scheduler* Scheduler::instance = 0;

Scheduler::Scheduler() {}

Scheduler* Scheduler::getInstance() {
   if (instance == nullptr) {
      instance = new Scheduler();
   }

   return instance;
}

void Scheduler::add(Subsystem* s) {
   subsystems.push_back(s);
}

void Scheduler::run() {
   for (Subsystem* s : subsystems) {
      (*s).periodic();
   }
}