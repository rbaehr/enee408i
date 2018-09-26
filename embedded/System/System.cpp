#include "System.h"

System::System() {
  mc_driver = MotorControllerDriver();

  pot_pins.POT_LEFT = A1;
  pot_pins.POT_RIGHT = A0;
}

void System::forward(int speed) {
  mc_driver.ccwLeft(speed);
  mc_driver.ccwRight(speed);
}

void System::backward(int speed) {
  mc_driver.cwLeft(speed);
  mc_driver.cwRight(speed);
}

void System::left(int speed) {
  mc_driver.cwLeft(speed);
  mc_driver.ccwRight(speed);
}

void System::right(int speed) {
  mc_driver.ccwLeft(speed);
  mc_driver.cwRight(speed);
}

void System::updateAdjustments() {
  pot_left = analogRead(pot_pins.POT_LEFT);
  pot_right = analogRead(pot_pins.POT_RIGHT);

  int remapped_left = map(pot_left, 0, 1023, ADJUST_MIN, ADJUST_MAX);
  int remapped_right = map(pot_right, 0, 1023, ADJUST_MIN, ADJUST_MAX);

  mc_driver.setLeftSpeedAdjust(remapped_left);
  mc_driver.setLeftSpeedAdjust(remapped_right);
}
