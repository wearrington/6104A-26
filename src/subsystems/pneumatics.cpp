namespace pneumatics {
    pros::ADIDigitalOut pneumatics ('A', false);
    void control {
        while (true) {
            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
                pneumatics.set_value(!pneumatics.get());
                pros::delay(50);
            }
        }
    }
}