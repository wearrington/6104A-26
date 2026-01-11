#include "main.h"
#include "lemlib/api.hpp"

void full_skills() {
    chassis.setPose(46.5, 11);
    chassis.moveToPoint(46.5, 46.6);
    chassis.turnToHeading(90);
    //drop match loader
    chassis.moveToPoint(58.3, 46.6);
    //run lower intake
    chassis.moveToPoint(53.5, 46.6);
    //retract match loader
    chassis.turnToHeading(0);
    chassis.moveToPoint(53.5, 57.75);
    chassis.turnToHeading(270);
    chassis.moveToPoint(-43.5, 57.75);
    chassis.turnToHeading(180);
    chassis.moveToPoint(-43.5, 46.6);
    chassis.turnToHeading(270);
    chassis.moveToPoint(-30, 46.6);
    //run full intake
    //drop match loader
    chassis.moveToPoint(-59, 46.6);
    //run lower intake
    chassis.moveToPoint(-30, 46.6);
    //run full intake
    //retract match loader
    chassis.moveToPoint(-39, 46.6);
    chassis.turnToHeading(180);
    chassis.moveToPoint(-39, -47);
    chassis.turnToHeading(90);
    chassis.moveToPoint(-30, -47);
    //run full intake
    //drop match loader
    chassis.moveToPoint(-59, -47);
    //run lower intake
    chassis.moveToPoint(-53, -47);
    //retract match loader
    chassis.turnToHeading(180);
    chassis.moveToPoint(-53, -57.5);
    chassis.turnToHeading(90);
    chassis.moveToPoint(44, -57.5);
    chassis.turnToHeading(0);
    chassis.moveToPoint(44, -47.4);
    chassis.turnToHeading(270);
    chassis.moveToPoint(30.5, -47.4);
    //run full intake
    //drop matchloader
    chassis.moveToPoint(58.3, -47.4);
    //run lower intake
    chassis.moveToPoint(30.5, -47.3);
    //run full intake
    //retract matchloader
    chassis.moveToPoint(37.8, -47.4);
    chassis.turnToHeading(0);
    chassis.moveToPoint(37.8, 0);
    chassis.turnToHeading(90);
    chassis.moveToPoint(100, 0); //ghost point to maintain speed, real point is (61.5, 0)
}