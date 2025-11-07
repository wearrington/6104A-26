#include "main.h"
#include <stdio.h>
#include <iostream>

namespace intake {
    pros::MotorGroup intake({10, -13});
    pros::Motor lower_intake(10);
    pros::Motor upper_intake(13); //Upper intake motor defined seperatly for color sorting
    pros::Optical optical_sensor(21); 
    typedef enum alliance_colors {
        SKILLS = 0, 
        RED = 1,
        BLUE = 2
    } color_type_e; 
    color_type_e alliance_color = RED; //Sets alliance color to red

    void control() {
        while (true) {
            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
                lower_intake.move_voltage(12000);
                switch (alliance_color) {
                    case RED:
                        if (160 < optical_sensor.get_hue() < 220) {
                            upper_intake.move_voltage(-12000); //Rejects the game object if it's blue
                        }
                        else {
                            upper_intake.move_voltage(12000);
                        }
                        break;
                    case BLUE:
                        if (optical_sensor.get_hue() < 50 or optical_sensor.get_hue() > 350) {
                            upper_intake.move_voltage(-12000); //Rejects the game object if it's red
                        }
                        else {
                            upper_intake.move_voltage(12000);
                        }
                        break;
                    case SKILLS:
                        upper_intake.move_voltage(12000); //Always scores during skills
                        break;
                }
            }

            else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
                intake.move_voltage(-12000); //outtake balls if the second right paddle is pressed
            }

            else {
                intake.move_voltage(0);
            }
            pros::delay(75); //Prevents processor from getting starved
            //printf("\n%f", optical_sensor.get_hue());
        }
    }
}