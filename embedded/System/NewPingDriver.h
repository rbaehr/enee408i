#ifndef _PING_DRIVER_HEADER_H_
#define _PING_DRIVER_HEADER_H_

#include "Arduino.h"

class NewPingDriver {
	public:

		NewPingDriver();
		NewPingDriver(
			unsigned char PING1,
			unsigned char PING2
			);

    getPing1();
    getPing2();
	private:
		long microsecondsToInches(long microseconds);

		// pin mappings
		unsigned char _PING1;
		unsigned char _PING2;

}

#endif
