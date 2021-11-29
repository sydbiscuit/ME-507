#include <Arduino.h>
#include <divideNOT.h>

void setup() {
  Serial.begin(115200);
  delay(2000);
  uint8_t x;
  x = 6;
  uint8_t y;
  y = 3;
  uint8_t z;
  z = yeet(x,y);
  Serial << z << endl;
  z = yeet(y,x);
  Serial << z << endl;

}

void loop() {
  // put your main code here, to run repeatedly:
}