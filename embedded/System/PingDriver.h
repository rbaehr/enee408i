#ifndef _PING_DRIVER_HEADER_H_
#define _PING_DRIVER_HEADER_H_

#include "Arduino.h"
#include "DataStructures.h"

class PingDriver {
 public:
  PingDriver();
  PingDriver(unsigned char pin);

  long getPing();

 private:
  unsigned char ping_pin;
  long microsecondsToInches(long microseconds);
};

#endif
