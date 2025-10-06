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
    color_type_e alliance_color = RED;
    color_type_e get_color() {
        while (true) {
            if (optical_sensor.get_hue() < 10 or optical_sensor.get_hue() > 355) {
                return RED;
            }

            else if (221 < optical_sensor.get_hue() < 240) {
                return BLUE;
            }
            
            else {
                return SKILLS;
            }
        }
    }

    void control() {
        while (true) {
            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
                lower_intake.move_voltage(12000);
            }

            else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
                lower_intake.move_voltage(-12000);
            }

            else {
                lower_intake.move_voltage(0);
            }

            if (get_color() == RED) {
                upper_intake.move_voltage(12000);
            }

            else if (get_color() != SKILLS) {
                upper_intake.move_voltage(-12000);
            }

            else {
                upper_intake.move_voltage(0);
            }

            printf("%d\n", get_color());
            pros::delay(50);
        }
    }
}