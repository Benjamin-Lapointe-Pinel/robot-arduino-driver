#ifndef ROBOT_IO_H
#define ROBOT_IO_H
#include "Arduino.h"

class RobotIO
{
  private:
    const int DATA;
    const int CLOCK;
    const int LATCH;
    byte outputs;

    RobotIO(int data, int clock, int latch);
    
  public:
    static RobotIO& get();
    
    void setDigitalOutput(int output, int value);
    byte sendOutputs();
};

#endif
