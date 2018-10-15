#include "System.h"

#define DIST_TURN_THRESH   12
#define DIST_MID_THRESH    8

#define TURN_DELAY         325

#define SPEED_HIGH         100
#define SPEED_MED          75
#define SPEED_LOW          25

#define LEFT_CW_CMD        0x01
#define LEFT_CCW_CMD       0x02
#define RIGHT_CW_CMD       0x04
#define RIGHT_CCW_CMD      0x08
#define PING_CMD           0xF0

System sys;

void setup() {
  Serial.begin(9600);

  sys = System(); 
  
  pinMode(8, OUTPUT);
}


void loop() {

  // update the pot adjustments

  int opcode = 0;
  int operand = 0;
  
  while ( !Serial.available() ) {
    sys.updateAdjustments();
  }
  opcode = Serial.read();
  
  while ( !Serial.available() ) {
    sys.updateAdjustments();
  }
  operand = Serial.read();
   
  switch ( opcode ) {
    
    case LEFT_CW_CMD:
    sys.mc_driver.cwLeft(operand);
    break;
    
    case LEFT_CCW_CMD:
    sys.mc_driver.ccwLeft(operand);
    break;
    
    case RIGHT_CW_CMD:
    sys.mc_driver.cwRight(operand);
    break;
    
    case RIGHT_CCW_CMD:
    sys.mc_driver.ccwRight(operand);
    break;
    
    case PING_CMD:
    long dist_left = sys.ping_driver_left.getPing();
    long dist_right = sys.ping_driver_right.getPing();
    long dist_mid = sys.ping_driver_right.getPing();
    
    Serial.println(dist_left);
    Serial.println(dist_right);
    Serial.println(dist_mid);
    break;
  }
}
