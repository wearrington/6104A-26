namespace angle_wing {
    pros::ADI::DigitalIn angle_wing_input ('B');
    pros::ADI::DigitalOut angle_wing_output ("B");

    void control() {
        while (true) {
            if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
                angle_wing_output.toggle();
            }
            pros::delay(100);
        }
    }
}