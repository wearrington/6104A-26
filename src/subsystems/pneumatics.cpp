#include "main.h"

namespace pneumatics {
    pros::adi::DigitalOut pneumatics_output ('A', false);
    pros::adi::DigitalIn pneumatics_input ('A');
    void control() {
        while (true) {
            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
                pneumatics_output.set_value(!pneumatics_input.get_value());
            }
            pros::delay(250);
        }
    }
}