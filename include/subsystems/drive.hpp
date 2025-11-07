#include "main.h"

namespace drive {
    extern pros::MotorGroup drive;
    extern pros::MotorGroup left_motors;
    extern pros::MotorGroup right_motors;
    extern pros::Rotation horizontal_tracking_wheel;
    extern pros::Rotation vertical_tracking_wheel;
    extern pros::IMU imu;
    extern bool driveLock;
    void control();
}