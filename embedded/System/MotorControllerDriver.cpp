#include "MotorControllerDriver.h"

MotorControllerDriver::MotorControllerDriver() {
  mc_pins.INA1 = 2;
  mc_pins.INB1 = 4;
	mc_pins.INA2 = 7;
  mc_pins.INB2 = 8;
  mc_pins.PWM1 = 3;
  mc_pins.PWM2 = 5;

  setup();
}

MotorControllerDriver::MotorControllerDriver(DataStructures::MotorControllerPins &pins) {
  mc_pins = pins;

  setup();
}

void MotorControllerDriver::setup() {
	pinMode(mc_pins.INA1, OUTPUT);
	pinMode(mc_pins.INB1, OUTPUT);
	pinMode(mc_pins.INA2, OUTPUT);
	pinMode(mc_pins.INB2, OUTPUT);
}

void MotorControllerDriver::cwLeft(int speed) {
  digitalWrite(mc_pins.INA1, HIGH);
  digitalWrite(mc_pins.INB1, LOW);
  analogWrite(mc_pins.PWM1, speed + left_speed_adjust);
}

void MotorControllerDriver::cwRight(int speed) {
  digitalWrite(mc_pins.INA2, LOW);
  digitalWrite(mc_pins.INB2, HIGH);
  analogWrite(mc_pins.PWM2, speed + right_speed_adjust);
}

void MotorControllerDriver::ccwLeft(int speed) {
  digitalWrite(mc_pins.INA1, LOW);
  digitalWrite(mc_pins.INB1, HIGH);
  analogWrite(mc_pins.PWM1, speed + left_speed_adjust);
}

void MotorControllerDriver::ccwRight(int speed) {
  digitalWrite(mc_pins.INA2, HIGH);
  digitalWrite(mc_pins.INB2, LOW);
  analogWrite(mc_pins.PWM2, speed + right_speed_adjust);
}

void MotorControllerDriver::setLeftSpeedAdjust(int speed) {
	left_speed_adjust = speed;
}

void MotorControllerDriver::setRightSpeedAdjust(int speed) {
	right_speed_adjust = speed;
}

int MotorControllerDriver::getLeftSpeedAdjust() {
	return left_speed_adjust;
}

int MotorControllerDriver::getRightSpeedAdjust() {
	return right_speed_adjust;
}
