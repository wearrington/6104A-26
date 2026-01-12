#include "main.h"
#include "lemlib/api.hpp"

namespace drive {
    pros::Controller controller(pros::E_CONTROLLER_MASTER);

    //drivetrain motors
    pros::MotorGroup drive ({-12, -3, -2, 20, 9, 10}, pros::MotorGearset::blue);
    pros::MotorGroup left_motors ({-12, -3, -2}, pros::MotorGearset::blue);
    pros::MotorGroup right_motors({20, 9, 10}, pros::MotorGearset::blue);

    //odometry sensors
    pros::Rotation vertical_encoder({8});
    lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, -5.75);
    pros::Rotation horizontal_encoder({11});
    lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_2, -5.75);
    pros::IMU imu({4});

    // odometry settings
    lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                                nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                                &horizontal_tracking_wheel, // horizontal tracking wheel 1
                                nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                                &imu // inertial sensor
);

    void control() {
        // loop forever
        while (true) {
            // get left y and right x positions
            int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

            // move the robot
            chassis.arcade(leftY, rightX);

            // delay to save resources
            pros::delay(25);
        }
    }
}