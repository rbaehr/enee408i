#include "System.h"

#define DIST_TURN_THRESH 12
#define DIST_MID_THRESH 8

#define TURN_DELAY 325

#define SPEED_HIGH 100
#define SPEED_MED 75
#define SPEED_LOW 25


#define SPEED_ZERO 6
#define SPEED_MULTI = 125 / (15-SPEED_ZERO)

System sys;

void setup() {
  Serial.begin(9600);

  sys = System(); 
}


void loop() {

  // update the pot adjustments
  sys.updateAdjustments();


  int command = 0;

  if ( Serial.available() ) {
    command = Serial.read();
  }

  int left_speed;
  int right_speed;

  if ( command < 250 ) {
    left_speed = ((command / 16) - SPEED_ZERO) * SPEED_MULTI;
    right_speed = ((command % 16) - SPEED_ZERO) * SPEED_MULTI;
  

    if ( left_speed >= 0 ) {
      sys.mc_driver.ccwLeft(left_speed);
    }
    else {
      sys.mc_driver.cwLeft(-1*left_speed);
    }
    if ( right_speed >= 0 ) {
      sys.mc_driver.cwRight(right_speed);
    }
    else {
      sys.mc_driver.ccwRight(-1*right_speed);
    }
  }


  else if ( command == 255 ) {

    long dist_left = sys.ping_driver_left.getPing();
    long dist_right = sys.ping_driver_right.getPing();
    long dist_mid = sys.ping_driver_mid.getPing();

    Serial.write(dist_left);
    Serial.write(dist_right);
    Serial.write(dist_mid); 
  }

  delay(10); 
    //forward(SPEED_LOW);
}
