#include "main.h"

namespace angel_wing {
    pros::adi::DigitalIn angel_wing_input ('B');
    pros::adi::DigitalOut angel_wing_output ('B');

    void control() {
        while (true) {
            if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
                angel_wing_output.set_value(!angel_wing_input.get_value());
            }
            pros::delay(50);
        }
    }
}