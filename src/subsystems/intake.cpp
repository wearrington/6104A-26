#include "main.h"

namespace intake {
    pros::MotorGroup intake({10, -13});
    pros::Motor lower_intake(10);
    pros::Motor upper_intake(-13);
    pros::Optical optical_sensor(1);

    void control() {
        while (true) {
            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
                intake.move_voltage(12000);
            }
            else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
                intake.move_voltage(-12000);
            }
            else {
                intake.move_voltage(0);
            }
        }
    }

    std::string get_color() {
        while (true) {
            if (optical_sensor.get_hue() < 10 or optical_sensor.get_hue() > 355) {
                return "red";
            }
            else if (221 < optical_sensor.get_hue() < 240) {
                return "blue";
            }
            else {
                return "null";
            }
        }
    }
}