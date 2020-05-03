#include "wheel.h"
#include "Arduino.h"


Wheel::Wheel(int in1, int in2, int pwm, int s) :
  IN1(in1),
  IN2(in2),
  PWM(pwm),
  robotIO(RobotIO::get())
{
  pinMode(PWM, OUTPUT);

  setSpeed(s);
}

void Wheel::setSpeed(int s)
{
  speed = (abs(s) % 256) * (s < 0 ? -1 : 1);
  
  robotIO.setDigitalOutput(IN1, speed < 0 ? HIGH : LOW);
  robotIO.setDigitalOutput(IN2, speed < 0 ? LOW : HIGH);
  analogWrite(PWM, abs(speed));
}

int Wheel::getSpeed()
{
  return speed;
}
