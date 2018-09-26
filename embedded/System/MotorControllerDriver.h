#ifndef _MOTOR_CONTROLLER_DRIVER_HEADER_H_
#define _MOTOR_CONTROLLER_DRIVER_HEADER_H_


#include "Arduino.h"
#include "DataStructures.h"

class MotorControllerDriver {

	public:

		// default pins
		MotorControllerDriver();
		MotorControllerDriver(DataStructures::MotorControllerPins &pins);

		void setLeftSpeedAdjust(int speed);
		void setRightSpeedAdjust(int speed);
		int getLeftSpeedAdjust();
		int getRightSpeedAdjust();

    void cwLeft(int speed);
    void cwRight(int speed);
    void ccwLeft(int speed);
    void ccwRight(int speed);

	private:
    DataStructures::MotorControllerPins mc_pins;

		void setup();

		int left_speed_adjust = 0;
		int right_speed_adjust = 0;

};

#endif
