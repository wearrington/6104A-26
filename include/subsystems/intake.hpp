#include "main.h"

namespace intake {
    extern pros::MotorGroup intake;
    extern pros::Motor lower_intake;
    extern pros::Motor upper_intake;
    extern pros::Optical optical_sensor;
    extern std::string alliance_color;
    void control();
    void get_color();
}