#include "locomotion.h"
#include "Arduino.h"

#define AIN1 7
#define AIN2 6
#define PWMA 10
#define ENCA 2
#define BIN1 5
#define BIN2 4
#define PWMB 11
#define ENCB 3


Locomotion& Locomotion::get()
{
	static Locomotion locomotion();
	return locomotion;
}

Locomotion::Locomotion() :
	left_wheel(AIN1, AIN2, PWMA),
	right_wheel(BIN1, BIN2, PWMB),
	left_wheel_ticks(0),
	right_wheel_ticks(0)
{
	attachInterrupt(digitalPinToInterrupt(ENCA), tick_left_wheel, CHANGE);
	attachInterrupt(digitalPinToInterrupt(ENCB), tick_right_wheel, CHANGE);
}

void Locomotion::tick_left_wheel()
{

}

void Locomotion::tick_right_wheel()
{
}
