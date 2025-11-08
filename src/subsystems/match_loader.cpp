#include "main.h"

namespace match_loader {
    pros::adi::DigitalIn match_loader_input ('A');
    pros::adi::DigitalOut match_loader_output ('A', false);
    void control() {
        while (true) {
            if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
                match_loader_output.set_value(!match_loader_input.get_value());
            }
            pros::delay(100);
        }
    }
}