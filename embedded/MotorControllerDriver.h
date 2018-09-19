#ifndef _MOTOR_CONTROLLER_DRIVER_HEADER_H_
#define _MOTOR_CONTROLLER_DRIVER_HEADER_H_


#include "Arduino.h"

class MotorControllerDriver {

	public:

		// default pins
		MotorControllerDriver();
		MotorControlerDriver(
			unsigned char INA1,
			unsigned char INA1,
			unsigned char INB1,
			unsigned char INA2,
			unsigned char INB2,
			unsigned char PWM1,
			unsigned char PWM2
			);


		void setLeftSpeedAdjust(int speed);
		void setRightSpeedAdjust(int speed);
		int getLeftSpeedAdjust();
		int getRightSpeedAdjust();

	private:
		int left_speed_adjust = 0;
		int right_speed_adjust = 0;

		// pin mappings
		unsigned char _INA1;
		unsigned char _INA1;
		unsigned char _INB1;
		unsigned char _INA2;
		unsigned char _INB2;
		unsigned char _PWM1;
		unsigned char _PWM2;

}

#endif
