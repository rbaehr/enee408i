#include "System.h"

System::System() {
  mc_driver = MotorControllerDriver();
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
