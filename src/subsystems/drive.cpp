#include "main.h"

namespace drive {
    pros::MotorGroup drive({-12, -3, -2, 20, 9, 10});
    pros::MotorGroup left_motors({-12, -3, -2}); //in order from back to front
    pros::MotorGroup right_motors({20, 9, 10});
    pros::Rotation vertical_tracking_wheel({8});
    pros::Rotation horizontal_tracking_Wheel({11});
    pros::IMU imu({4});
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    bool driveLock = true;

    void control() {
        chassis.drive_brake_set(MOTOR_BRAKE_COAST);
        while (true) {
            if (!driveLock) {
                chassis.opcontrol_arcade_standard(ez::SPLIT); // Standard split arcade
            }
            if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT) && master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
                driveLock = !driveLock;
            }
            if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
                autonomous();
            }
            pros::delay(50);
        }
    }
}