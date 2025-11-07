#include "main.h"

namespace pneumatics {
    extern pros::adi::DigitalIn pneumatics_input;
    extern pros::adi::DigitalOut pneumatics_output;
    void control();
}