#include <Arduino.h>
#include <PrintStream.h>
//#include <Servo.h>

//Servo ESC;     // create servo object to control the ESC


int potValue;  // value from the analog pin
void setup() 
{
  // Attach the ESC signal wire six pins up from the bottom of CN9.
  // make that pin an output PWM signal.
  pinMode(PB4, OUTPUT);  // timer 3 channel 1 

  Serial.begin(115200);

}
void loop() 
{
  //potValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
  //ESC.write(potValue);    // Send the signal to the ESC

  potValue = analogRead(PA_0);   // reads the value of the potentiometer (value between 0 and 1023)
  potValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(PB4, potValue);
  Serial << potValue << endl;
  delay(20);
}