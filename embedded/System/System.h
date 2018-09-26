#ifndef _SYSTEM_HEADER_H_
#define _SYSTEM_HEADER_H_

#include "Arduino.h"
#include "MotorControllerDriver.h"

class System {

 public:

  System();

  void updateAdjustments();

  void forward(int speed);
  void backward(int speed);
  void left(int speed);
  void right(int speed);

 private:


  MotorControllerDriver mc_driver;

};

#endif
