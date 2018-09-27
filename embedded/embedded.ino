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


  int command = 0;

  if ( Serial.available() ) {
    command = Serial.read();
  }

  if ( command == 1 ) {

    int left_speed = 0;
    int right_speed = 0;


    if ( Serial.available() ) {
      left_speed = Serial.read();
    }
    if ( Serial.available() ) {
      right_speed = Serial.read();
    }

    PRINTLN("%d, %d", left_speed, right_speed);

    if ( left_speed >= 0 ) {
      sys.mc_driver.ccwLeft(left_speed);
    }
    else {
      sys.mc_driver.cwLeft(-1*left_speed);
    }
    if ( right_speed >= 0 ) {
      sys.mc_driver.ccwRight(right_speed);
    }
    else {
      sys.mc_driver.cwRight(-1*right_speed);
    }
  }

  else if ( command == 255 ) {

    long dist_left = sys.ping_driver_left.getPing();
    long dist_right = sys.ping_driver_right.getPing();
    long dist_mid = sys.ping_driver_right.getPing();

    Serial.write(dist_left);
    Serial.write(dist_right);
    Serial.write(dist_mid); 
  }

  delay(10); 
    //forward(SPEED_LOW);
}
