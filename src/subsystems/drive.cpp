#include "main.h"

namespace drive {
    pros::MotorGroup drive ({-12, -3, -2, 20, 9, 10}, pros::MotorGearset::blue);
    pros::MotorGroup left_motors ({-12, -3, -2}, pros::MotorGearset::blue);
    pros::MotorGroup right_motors({20, 9, 10});
    pros::Controller controller(pros::E_CONTROLLER_MASTER);

    void control() {
    // loop forever
    while (true) {
        // get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        //chassis.arcade(leftY, rightX);

        // delay to save resources
        pros::delay(25);
    }
}
}