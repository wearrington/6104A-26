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
            pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
                            (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
                            (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);  // Prints status of the emulated screen LCDs

            // Arcade control scheme
            int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
            int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
            left_motors.move(dir - turn);                      // Sets left motor voltage
            right_motors.move(dir + turn);                     // Sets right motor voltage
            pros::delay(20);                               // Run for 20 ms then update
        }
    }
}