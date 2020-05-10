#include "wheel.h"
#include "Arduino.h"
#include "robotio.h"


Wheel::Wheel(int in1, int in2, int pwm, int s) :
	IN1(in1),
	IN2(in2),
	PWM(pwm),
	ticks(0)
{
	pinMode(PWM, OUTPUT);
	setSpeed(s);
}

void Wheel::tick()
{
	ticks++;
}

void Wheel::setSpeed(int s)
{
	speed = (abs(s) % 256) * (s < 0 ? -1 : 1);

	RobotIO::get().setDigitalOutput(IN1, speed < 0 ? HIGH : LOW);
	RobotIO::get().setDigitalOutput(IN2, speed < 0 ? LOW : HIGH);
	analogWrite(PWM, abs(speed));
}

int Wheel::getSpeed()
{
	return speed;
}


