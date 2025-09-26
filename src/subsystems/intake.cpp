#include "main.h"

namespace intake {
    pros::Motor intake(10);


    void control () {
        while (true) {
            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
                intake.move(127);
            }
            else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
                intake.move(-127);
            }
            else {
                intake.move(0);
            }
        }
    }
}