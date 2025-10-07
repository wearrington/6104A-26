#include "main.h"
#include "subsystems/drive.hpp"
#include "subsystems/intake.hpp"
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

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
	chassis.odom_tracker_front_set(&vertical_tracking_wheel);
	chassis.odom_tracker_right_set(&horizontal_tracking_wheel);
	//chassis.opcontrol_curve_buttons_toggle(false);  // Disable modifying curves through the controller
    //chassis.opcontrol_curve_default_set(2.1);
	chassis.opcontrol_drive_activebrake_set(0.5);
	chassis.initialize();
	ez::as::initialize();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	printf("This is auton, TEST");
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	pros::Task drive(drive::control);
	pros::Task intake(intake::control);
	while (true) {
		//printf("horizontal: %f /n", horizontal_tracking_wheel);
		//printf("vertical: %f /n", vertical_tracking_wheel);
		pros::delay(50);
	}
}