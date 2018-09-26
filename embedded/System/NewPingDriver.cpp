#include "NewPingDriver.h"

NewPingDriver::NewPingDriver()
{
		_PING1 = 6;
		_PING2 = 13;
}

NewPingDriver::NewPingDriver(
	unsigned char PING1,
	unsigned char PING2
){
	_PING1 = PING1;
	_PING2 = PING2;
}

// Public
long NewPingDriver::PING1(){
	pinMode(PING1, OUTPUT);
  digitalWrite(PING1, LOW);
  delayMicroseconds(2);
  digitalWrite(PING1, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING1, LOW);

  pinMode(PING1, INPUT);

  return microsecondsToInches(pulseIn(PING1, HIGH));
}

long NewPingDriver::PING2(){
	pinMode(PING2, OUTPUT);
  digitalWrite(PING2, LOW);
  delayMicroseconds(2);
  digitalWrite(PING2, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING2, LOW);

  pinMode(PING2, INPUT);

  return microsecondsToInches(pulseIn(PING2, HIGH));
}
// private
long NewPingDriver::microsecondsToInches(long microseconds){
	return microseconds / 74 / 2;
}
