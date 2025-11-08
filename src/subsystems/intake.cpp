#include "main.h"
#include <stdio.h>
#include <iostream>

namespace intake {
    pros::MotorGroup intake({10, -13});
    pros::Motor lower_intake(10);
    pros::Motor upper_intake(-13); //Upper intake motor defined seperatly for color sorting
    pros::Optical optical_sensor(21);
    pros::adi::DigitalIn hood_input ('H');
    pros::adi::DigitalOut hood_output ('H', false);

    void control() {
        while (true) {
            if (!master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
                hood_output.set_value(false);
            }

            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
                intake.move_voltage(12000);
                hood_output.set_value(true);
            }

            else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) { //intake balls without scoring
                lower_intake.move_voltage(12000);
            }

            else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { //outtake/score on low goal
                lower_intake.move_voltage(-12000);
            }

            else {
                intake.move_voltage(0);
            }
            pros::delay(75);
        }
    }
}