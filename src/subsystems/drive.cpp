#include "main.h"
namespace drive {
    pros::MotorGroup drivetrain_motors({12, 3, 2, -20, -9, -10});
    pros::MotorGroup left_motors({12, 3, 2}); //in order from back to front
    pros::MotorGroup right_motors({-20, -9, -10});
    pros::Rotation vertical_tracking_wheel({8});
    pros::Rotation horizontal_tracking_Wheel({11});
    pros::IMU imu({4});
    pros::Controller master(pros::E_CONTROLLER_MASTER);


    void control() {
        while (true) {
            chassis.opcontrol_arcade_standard(ez::SPLIT); // Standard split arcade
            //printf("drive running\n");
            pros::delay(20); // ez::util::DELAY_TIME
        }
    }
}