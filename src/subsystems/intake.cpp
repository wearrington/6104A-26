#include "main.h"
#include <stdio.h>
#include <iostream>

namespace intake {
    pros::MotorGroup intake({10, -13});
    pros::Motor lower_intake(10);
    pros::Motor upper_intake(-13);
    pros::Optical optical_sensor(21);
    pros::ADIDigitalOut pneumatics ('A', false);
    typedef enum alliance_colors {
        SKILLS = 0, 
        RED = 1,
        BLUE = 2
    } color_type_e; 
    color_type_e alliance_color = RED;

    void control() {
        while (true) {
             if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
                lower_intake.move_voltage(12000);
                switch (alliance_color) {
                    case RED:
                        if (221 < optical_sensor.get_hue() < 240) {
                            upper_intake.move_voltage(-12000);
                        }
                        else {
                            upper_intake.move_voltage(12000);
                        }
                        break;
                    case BLUE:
                        if (optical_sensor.get_hue() < 10 or optical_sensor.get_hue() > 355) {
                            upper_intake.move_voltage(-12000);
                        }
                        else {
                            upper_intake.move_voltage(12000);
                        }
                        break;
                    case SKILLS:
                        upper_intake.move_voltage(12000);
                        break;
                }
            }

            else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
                intake.move_voltage(-12000);
            }
            else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
                pneumatics.set_value(true);
                pros::delay(10);}
            else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
                pneumatics.set_value(false);
                pros::delay(10);}
            else {
                intake.move_voltage(0);
            }
        }
    }
}