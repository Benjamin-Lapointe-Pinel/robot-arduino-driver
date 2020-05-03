#include "robotio.h"

#define DATA_PIN 12
#define CLOCK_PIN 4
#define LATCH_PIN 13


RobotIO::RobotIO(int data, int clock, int latch) :
  DATA(data),
  CLOCK(clock),
  LATCH(latch),
  outputs(0)
{

  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
}

RobotIO& RobotIO::get()
{
  static RobotIO robotIO(DATA_PIN, CLOCK_PIN, LATCH_PIN);
  return robotIO;
}

void RobotIO::setDigitalOutput(int output, int value)
{
  byte mask = 1 << output;

  switch (value)
  {
    case LOW: outputs &= ~mask; break;
    case HIGH: outputs |= mask; break;
  }
}

byte RobotIO::sendOutputs()
{
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, outputs);
  digitalWrite(LATCH, HIGH);
  return outputs;
}
