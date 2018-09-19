#include "MotorControllerDriver.h"

MotorControllerDriver::MotorControllerDriver() 
{
		_INA1 = 2;
		_INB1 = 4;
		_INA2 = 7;
		_INB2 = 8;
		_PWM1 = 3;
		_PWM2 = 5;
}

MotorControllerDriver::MotorControlerDriver(
			unsigned char INA1,
			unsigned char INA1,
			unsigned char INB1,
			unsigned char INA2,
			unsigned char INB2,
			unsigned char PWM1,
			unsigned char PWM2
			) 
{
		_INA1 = INA1;
		_INB1 = INB1;
		_INA2 = INA2;
		_INB2 = INB2;
		_PWM1 = PWM1;
		_PWM2 = PWM2;
}


