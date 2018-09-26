#include "PingDriver.h"

PingDriver::PingDriver(unsigned char pin) {
  ping_pin = pin;
  pinMode(ping_pin, OUTPUT);
}

// Public
long PingDriver::getPing(){
	pinMode(ping_pin, OUTPUT);
  digitalWrite(ping_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(ping_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(ping_pin, LOW);

  pinMode(ping_pin, INPUT);

  return microsecondsToInches(pulseIn(ping_pin, HIGH));
}

// private
long PingDriver::microsecondsToInches(long microseconds){
	return microseconds / 74 / 2;
}
