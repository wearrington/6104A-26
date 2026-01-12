#include "main.h"

namespace intake {
    extern pros::MotorGroup intake({10, -13});
    extern pros::Motor lower_intake(10);
    extern pros::Motor upper_intake(-13);

    void control();
}