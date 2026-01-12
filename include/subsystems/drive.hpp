#include "main.h"

namespace drive {
    extern pros::MotorGroup drive;
    extern pros::MotorGroup left_motors;
    extern pros::MotorGroup right_motors;
    extern lemlib::OdomSensors sensors;
    extern lemlib::Drivetrain drivetrain;
    extern lemlib::Chassis chassis;

    void control();
}