#include main.h

namespace intake {
    pros::Motor intake(10);


    void control (
        while (true) {
            if (master.get_digital(X)) {
                intake.move(127);
            }
            else if (master.get_digital(B)) {
                intake.move(-127);
            }
            else {
                intake.move(0);
            }
        }
    )
}