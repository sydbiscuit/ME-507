#include <Arduino.h>
#include <PrintStream.h>

int potValue;  // value from the analog pin

void setup() 
{
 // Attach the ESC signal wire six pins up from the bottom of CN9.
  // make that pin an output PWM signal.
  pinMode(PB4, OUTPUT);  // timer 3 channel 1 
 
  Serial.begin(115200);
  analogWriteResolution(8);    // set 8-bit timer channel
  
  potValue = 15;
  analogWrite(PB4, potValue);    // potValue(10) sends a 1ms pulse width and is needed to send a stop signal to the ESC. This value needs to be present when the ESC is plugged in
  analogWriteFrequency(50);  //50 Hz freq
  delay(30000); 
  Serial << "The starting value is: " << potValue << endl;

}

void loop() 
{
  // for(uint8_t index=0; index < 100; index++)
  // {
  //   potValue = 24;
  //   analogWrite(PB4, potValue);    // potValue(10) sends a 1ms pulse width and is needed to send a stop signal to the ESC. This value needs to be present when the ESC is plugged in 
  //   analogWriteFrequency(50);  //50 Hz freq
  //   Serial << potValue << endl;
  // }
  
  // Serial << "" << endl;
  // potValue = 10;
  // analogWrite(PB4, potValue);    // potValue(10) sends a 1ms pulse width and is needed to send a stop signal to the ESC. This value needs to be present when the ESC is plugged in 
  // analogWriteFrequency(50);  //50 Hz freq
  // Serial << potValue << endl;
  // Serial << "" << endl;
  // delay(5000); 
  
}