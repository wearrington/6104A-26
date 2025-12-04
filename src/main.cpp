#include "main.h"
#include "subsystems/drive.hpp"
#include "subsystems/intake.hpp"
#include "subsystems/match_loader.hpp"
#include "subsystems/angel_wing.hpp"
#include <stdio.h>
// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {-12, -3, -2},     // Left Chassis Ports (negative port will reverse it!)
    {20, 9, 19},  // Right Chassis Ports (negative port will reverse it!)
    4,       // IMU Port
    4.25,   // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    450);  // Wheel RPM = cartridge * (motor gear / wheel gear)

ez::tracking_wheel horizontal_tracking_wheel(11, 2.125, 0);
ez::tracking_wheel vertical_tracking_wheel(-8, 2.125, 0.75);

void initialize() {
	chassis.opcontrol_curve_buttons_toggle(false);
  chassis.opcontrol_curve_default_set(2.1);
	chassis.initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  drive::drive.move_voltage(12000);
  pros::delay(300);
  drive::drive.move_voltage(0);
}

void opcontrol() {
	pros::Task drive(drive::control);
	pros::Task intake(intake::control);
	pros::Task match_loader(match_loader::control);
  pros::Task angel_wing(angel_wing::control);
}
