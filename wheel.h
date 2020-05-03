#ifndef WHEEL_H
#define WHEEL_H

#include "robotio.h"


class Wheel
{
	private:
    const RobotIO& robotIO;
		const int IN1;
		const int IN2;
		const int PWM;
		int speed;
	public:
		Wheel(int in1, int in2, int pwm, int s = 0);
		int getSpeed();
		void setSpeed(int s);
};

#endif
