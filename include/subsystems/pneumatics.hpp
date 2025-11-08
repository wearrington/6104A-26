#include "main.h"

namespace pneumatics {
    extern pros::adi::DigitalOut pneumatics_output;
    extern pros::adi::DigitalIn pneumatics_input;
    void control();
}