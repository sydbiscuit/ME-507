#include <Arduino.h>
#include <PrintStream.h>
#include <add_it.h>

void setup() 
{
  Serial.begin(115200);
  delay(2000);
  float x;
  x = add_it(1.25, 5);
  Serial << x << endl;
}

void loop() {
  // put your main code here, to run repeatedly:
}