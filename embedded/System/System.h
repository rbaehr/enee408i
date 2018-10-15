#ifndef _SYSTEM_HEADER_H_
#define _SYSTEM_HEADER_H_

#include "Arduino.h"
#include "MotorControllerDriver.h"
#include "PingDriver.h"

#define ADJUST_MIN -25
#define ADJUST_MAX 25

class System {

 public:

  System();

  MotorControllerDriver mc_driver;
  PingDriver ping_driver_left = PingDriver(6);
  PingDriver ping_driver_right = PingDriver(13);
  PingDriver ping_driver_mid = PingDriver(10);

  void updateAdjustments();

  void forward(int speed);
  void backward(int speed);
  void left(int speed);
  void right(int speed);

 private:

  int pot_left;
  int pot_right;

  DataStructures::PotPins pot_pins;


};

#endif
