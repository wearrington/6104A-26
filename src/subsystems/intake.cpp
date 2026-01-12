#include "main.h"

namespace intake {
    pros::MotorGroup intake({10, -13});
    pros::Motor lower_intake(10);
    pros::Motor upper_intake(-13);

    void control() {
        while (true) {
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) { //score balls
                intake.move_voltage(12000);
            }
            else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) { //intake balls
                lower_intake.move_voltage(12000);
            }
            else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { //outtake balls
                lower_intake.move_voltage(-12000);
            }
            else {
                intake.move_voltage(0);
            }
            pros::delay(20);
        }
    }
}