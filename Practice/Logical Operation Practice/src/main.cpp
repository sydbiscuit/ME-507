#include <Arduino.h>
#include <PrintStream.h>

void setup()
{
Serial.begin(115200);
delay(2000);
uint8_t myvar = 0b00111110;
uint8_t myvar2 = 0b01100001;
uint8_t myvar3;
myvar3 = myvar || myvar2;
Serial << myvar3 << endl;
}

void loop() {
  // put your main code here, to run repeatedly:
}