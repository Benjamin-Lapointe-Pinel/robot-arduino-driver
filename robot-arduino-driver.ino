#include "robotio.h"

RobotIO& robotIO = RobotIO::get();

void setup() {
	Serial.begin(9600);

	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	robotIO.sendOutputs();

	delay(500);
}
