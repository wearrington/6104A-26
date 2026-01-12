#include "main.h"
#include "lemlib/api.hpp"
#include "subsystems/drive.hpp"

// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

void full_skills() {
    chassis.setPose(46.5, 11, 0);
    chassis.moveToPoint(46.5, 46.6, 5000);
    chassis.turnToHeading(90, 5000);
    //drop match loader
    chassis.moveToPoint(58.3, 46.6, 5000);
    //run lower intake
    chassis.moveToPoint(53.5, 46.6, 5000);
    //retract match loader
    chassis.turnToHeading(0, 5000);
    chassis.moveToPoint(53.5, 57.75, 5000);
    chassis.turnToHeading(270, 5000);
    chassis.moveToPoint(-43.5, 57.75, 5000);
    chassis.turnToHeading(180, 5000);
    chassis.moveToPoint(-43.5, 46.6, 5000);
    chassis.turnToHeading(270, 5000);
    chassis.moveToPoint(-30, 46.6, 5000);
    //run full intake
    //drop match loader
    chassis.moveToPoint(-59, 46.6, 5000);
    //run lower intake
    chassis.moveToPoint(-30, 46.6, 5000);
    //run full intake
    //retract match loader
    chassis.moveToPoint(-39, 46.6, 5000);
    chassis.turnToHeading(180, 5000);
    chassis.moveToPoint(-39, -47, 5000);
    chassis.turnToHeading(90, 5000);
    chassis.moveToPoint(-30, -47, 5000);
    //run full intake
    //drop match loader
    chassis.moveToPoint(-59, -47, 5000);
    //run lower intake
    chassis.moveToPoint(-53, -47, 5000);
    //retract match loader
    chassis.turnToHeading(180, 5000);
    chassis.moveToPoint(-53, -57.5, 5000);
    chassis.turnToHeading(90, 5000);
    chassis.moveToPoint(44, -57.5, 5000);
    chassis.turnToHeading(0, 5000);
    chassis.moveToPoint(44, -47.4, 5000);
    chassis.turnToHeading(270, 5000);
    chassis.moveToPoint(30.5, -47.4, 5000);
    //run full intake
    //drop matchloader
    chassis.moveToPoint(58.3, -47.4, 5000);
    //run lower intake
    chassis.moveToPoint(30.5, -47.3, 5000);
    //run full intake
    //retract matchloader
    chassis.moveToPoint(37.8, -47.4, 5000);
    chassis.turnToHeading(0, 5000);
    chassis.moveToPoint(37.8, 0, 5000);
    chassis.turnToHeading(90, 5000);
    chassis.moveToPoint(100, 0, 5000); //ghost point to maintain speed, real point is (61.5, 0)
}