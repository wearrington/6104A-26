#include "main.h"

namespace intake {
    extern pros::MotorGroup intake;
    extern pros::Motor lower_intake;
    extern pros::Motor upper_intake;
    extern pros::Optical optical_sensor;
    void control();
    void get_color();
}