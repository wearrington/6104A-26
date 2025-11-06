#include "main.h"

namespace pneumatics {
    pros::adi::DigitalOut pneumatics_output ('A', false);
    pros::adi::DigitalIn pneumatics_input ('A');
    pros::adi::DigitalOut hood_lift ('H', flase);
    void control() {
        while (true) {
            if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
                pneumatics_output.set_value(!pneumatics_input.get_value());
            }
            else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
                hood_lift.set_value(true);
            }
            else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
                hood_lift.set_value(false);
            }
            pros::delay(100);
        }
    }
}