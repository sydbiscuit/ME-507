#include <Arduino.h>
#include <PrintStream.h>


int potValue;  // value from the analog pin

void setup() 
{
 // Attach the ESC signal wire six pins up from the bottom of CN9.
  // make that pin an output PWM signal.

  pinMode(PC7, OUTPUT);  // timer 3 channel 1 
  pinMode(PA9, OUTPUT);  // timer 3 channel 1 
  

  Serial.begin(115200);
  analogWriteResolution(8);    // set 8-bit timer channel

  potValue = 13;
  analogWrite(PC7, potValue);
  analogWrite(PA9, potValue);
  analogWriteFrequency(50);
  Serial <<  "first time " << potValue << endl;
  delay(1); 

}

void loop() 
{
  potValue = 13;
  analogWrite(PC7, potValue);
  analogWrite(PA9, potValue);
  analogWriteFrequency(50);
  Serial <<  potValue << endl;
  delay(1000);

  potValue = 17;                       // potValue(13) stop signal, potValue (26) max rpm
  // potValue(10) sends a 1ms pulse width and is needed to send a stop signal to the ESC. This value needs to be present when the ESC is plugged in
  analogWrite(PC7, potValue);
  analogWrite(PA9, potValue);
  analogWriteFrequency(50);  //50 Hz freq 
  Serial <<  potValue << endl;
  delay(500);

}