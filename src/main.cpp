#include "main.h"
#include "subsystems/drive.hpp"
#include "subsystems/intake.hpp"
#include "subsystems/pneumatics.hpp"
#include <stdio.h>
#include "autons.hpp"

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
	pneumatics::init();
	default_constants();
	chassis.odom_tracker_front_set(&vertical_tracking_wheel);
	chassis.odom_tracker_right_set(&horizontal_tracking_wheel);
	//chassis.opcontrol_curve_buttons_toggle(false);  // Disable modifying curves through the controller
    //chassis.opcontrol_curve_default_set(2.1);
	ez::as::auton_selector.autons_add({
		{"Drive\n\nDrive forward and come back", drive_example},
		{"Turn\n\nTurn 3 times.", turn_example},
		{"Drive and Turn\n\nDrive forward, turn, come back", drive_and_turn},
		{"Drive and Turn\n\nSlow down during drive", wait_until_change_speed},
		{"Swing Turn\n\nSwing in an 'S' curve", swing_example},
		{"Motion Chaining\n\nDrive forward, turn, and come back, but blend everything together :D", motion_chaining},
		{"Combine all 3 movements", combining_movements},
		{"Interference\n\nAfter driving forward, robot performs differently if interfered or not", interfered_example},
		{"Simple Odom\n\nThis is the same as the drive example, but it uses odom instead!", odom_drive_example},
		{"Pure Pursuit\n\nGo to (0, 30) and pass through (6, 10) on the way.  Come back to (0, 0)", odom_pure_pursuit_example},
		{"Pure Pursuit Wait Until\n\nGo to (24, 24) but start running an intake once the robot passes (12, 24)", odom_pure_pursuit_wait_until_example},
		{"Boomerang\n\nGo to (0, 24, 45) then come back to (0, 0, 0)", odom_boomerang_example},
		{"Boomerang Pure Pursuit\n\nGo to (0, 24, 45) on the way to (24, 24) then come back to (0, 0, 0)", odom_boomerang_injected_pure_pursuit_example},
		{"Measure Offsets\n\nThis will turn the robot a bunch of times and calculate your offsets for your tracking wheels.", measure_offsets},
	});
	chassis.initialize();
	pros::delay(3000);
    ez::as::initialize();
	//chassis.pid_tuner_toggle();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  	chassis.pid_targets_reset();                // Resets PID targets to 0
	chassis.drive_imu_reset();                  // Reset gyro position to 0
	chassis.drive_sensor_reset();               // Reset drive sensors to 0
	chassis.odom_xyt_set(0_in, 0_in, 0_deg);    // Set the current position, you can start at a specific position with this
	chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency
	if (!drive::driveLock) {
		ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
	}
}

/**
 * Simplifies printing tracker values to the brain screen
 */
void screen_print_tracker(ez::tracking_wheel *tracker, std::string name, int line) {
  std::string tracker_value = "", tracker_width = "";
  // Check if the tracker exists
  if (tracker != nullptr) {
    tracker_value = name + " tracker: " + util::to_string_with_precision(tracker->get());             // Make text for the tracker value
    tracker_width = "  width: " + util::to_string_with_precision(tracker->distance_to_center_get());  // Make text for the distance to center
  }
  ez::screen_print(tracker_value + tracker_width, line);  // Print final tracker text
}

/**
 * Ez screen task
 * Adding new pages here will let you view them during user control or autonomous
 * and will help you debug problems you're having
 */
void ez_screen_task() {
  while (true) {
    // Only run this when not connected to a competition switch
    if (!pros::competition::is_connected()) {
      // Blank page for odom debugging
      if (chassis.odom_enabled() && !chassis.pid_tuner_enabled()) {
        // If we're on the first blank page...
        if (ez::as::page_blank_is_on(0)) {
          // Display X, Y, and Theta
          ez::screen_print("x: " + util::to_string_with_precision(chassis.odom_x_get()) +
                               "\ny: " + util::to_string_with_precision(chassis.odom_y_get()) +
                               "\na: " + util::to_string_with_precision(chassis.odom_theta_get()),
                           1);  // Don't override the top Page line

          // Display all trackers that are being used
          screen_print_tracker(chassis.odom_tracker_left, "l", 4);
          screen_print_tracker(chassis.odom_tracker_right, "r", 5);
          screen_print_tracker(chassis.odom_tracker_back, "b", 6);
          screen_print_tracker(chassis.odom_tracker_front, "f", 7);
        }
      }
    }

    // Remove all blank pages when connected to a comp switch
    else {
      if (ez::as::page_blank_amount() > 0)
        ez::as::page_blank_remove_all();
    }

    pros::delay(ez::util::DELAY_TIME);
  }
}
pros::Task ezScreenTask(ez_screen_task);

void opcontrol() {
	pros::Task drive(drive::control);
	pros::Task intake(intake::control);
	pros::Task pneumatics(pneumatics::control);
	while (true) {
	// Trigger the selected autonomous routine
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B) && master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
		autonomous();
	}
		//printf("horizontal: %f /n", horizontal_tracking_wheel);
		//printf("vertical: %f /n", vertical_tracking_wheel);
		pros::delay(50);
	}
}