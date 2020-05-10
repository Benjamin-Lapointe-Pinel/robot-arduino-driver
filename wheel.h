#ifndef WHEEL_H
#define WHEEL_H


class Wheel
{
	private:
		const int IN1;
		const int IN2;
		const int PWM;
		volatile int ticks;
		int speed;
	public:
		Wheel(int in1, int in2, int pwm, int s = 0);
		void tick();
		int getSpeed();
		void setSpeed(int s);
};

#endif
