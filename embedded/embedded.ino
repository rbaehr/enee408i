#include "System.h"

#define DIST_TURN_THRESH 12
#define DIST_MID_THRESH 8

#define TURN_DELAY 325

#define SPEED_HIGH 100
#define SPEED_MED 75
#define SPEED_LOW 25

System sys;

void setup() {
  Serial.begin(9600);

  sys = System(); 
}


void loop() {

  // update the pot adjustments
  sys.updateAdjustments();
/*
  long inch_left = sys.ping_driver_left.getPing();
  long inch_right = sys.ping_driver_right.getPing();
  long inch_mid = sys.ping_driver_mid.getPing();

  if ( inch_left > DIST_TURN_THRESH && inch_right > DIST_TURN_THRESH && inch_mid > DIST_MID_THRESH ) {
    sys.forward(SPEED_LOW); 
  }
  else if ( inch_mid <= DIST_MID_THRESH ) {
    if ( inch_left < inch_right ) {
      sys.right(SPEED_LOW);
    }
    else {
      sys.left(SPEED_LOW);
    }
  }
  else if ( inch_left > DIST_TURN_THRESH && inch_right <= DIST_TURN_THRESH ) {
    sys.left(SPEED_LOW);
    delay(TURN_DELAY);
  }
  else if ( inch_left <= DIST_TURN_THRESH && inch_right > DIST_TURN_THRESH ) {
    sys.right(SPEED_LOW);
    delay(TURN_DELAY);
  }
  else {
    if ( inch_left < inch_right ) {
      sys.right(SPEED_LOW);
      delay(TURN_DELAY);
    }
    else {
      sys.left(SPEED_LOW);
      delay(TURN_DELAY);
    }  
  }
  
*/
  
  delay(100);
  
    //forward(SPEED_LOW);
}
