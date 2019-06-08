/**
* Defines methods for a robot subsystem.
*
* @author Finn Frankis
* @since 6/2/19
*/

#include <subsystem.hpp>
#include <scheduler.hpp>

Subsystem::Subsystem() {
   Scheduler::getInstance()->add(this);
}