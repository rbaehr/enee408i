#ifndef _DATA_STRUCTURES_H_
#define _DATA_STRUCTURES_H_


namespace DataStructures {

  typedef struct MotorControllerPins {
    unsigned char INA1;
    unsigned char INB1;
    unsigned char INA2;
    unsigned char INB2;
    unsigned char PWM1;
    unsigned char PWM2;
  } MotorControllerPins;

  typedef struct PingPins {
    unsigned char PING1;
    unsigned char PING2;
  } PingPins;

}

#endif
