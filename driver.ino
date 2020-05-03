#include "robotio.h"
#include "wheel.h"

#define AIN1 7
#define AIN2 6
#define BIN1 5
#define BIN2 4
#define PWMA 10
#define PWMB 11


void setup() {
	Serial.begin(9600);

	pinMode(LED_BUILTIN, OUTPUT);

	attachInterrupt(digitalPinToInterrupt(2), increment_left_encoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), increment_right_encoder, CHANGE);
}



RobotIO& robotIO = RobotIO::get();
Wheel left_wheel(AIN1, AIN2, PWMA);
Wheel right_wheel(BIN1, BIN2, PWMB);

volatile int left_encoder = 0;
volatile int right_encoder = 0;

void loop() {
	left_wheel.setSpeed(63);
	right_wheel.setSpeed(-63);
	robotIO.sendOutputs();

  Serial.print(left_encoder, DEC);
  Serial.print(' ');
  Serial.print(right_encoder, DEC);
  Serial.println();
  delay(500);
}


void increment_left_encoder()
{
  left_encoder++;
}

void increment_right_encoder()
{
  right_encoder++;
}
