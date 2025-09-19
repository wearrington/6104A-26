namespace drive {
pros::MotorGroup drivetrain_motors({12, 3, 2, -20, -9, -10});
pros::MotorGroup left_motors({12, 3, 2}); //in order from back to front
pros::MotorGroup right_motors({-20, -9, -10});
pros::Rotation vertical_tracking_wheel({8}):
pros::Rotation horizontal_tracking_Wheel({11});
pros::imu imu({4});
}