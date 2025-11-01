#include "main.h"
#include <stdio.h>
#include <iostream>

namespace intake {
    pros::MotorGroup intake({10, -13});
    pros::Motor lower_intake(10);
    pros::Motor upper_intake(-13);
    pros::Optical optical_sensor(21);
    typedef enum alliance_colors {
        SKILLS = 0, 
        RED = 1,
        BLUE = 2
    } color_type_e; 
    color_type_e alliance_color = SKILLS;

    void control() {
        while (true) {
             if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
                lower_intake.move_voltage(12000);
                if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
                    upper_intake.move_voltage(-12000);
                }
                else {
                    upper_intake.move_voltage(12000);
                }
            }
            else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
                intake.move_voltage(-12000);
            }
            else {
                intake.move_voltage(0);
            }
            pros::delay(20);
        }
    }
}