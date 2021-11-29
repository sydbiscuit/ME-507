#include <Arduino.h>
#include <PrintStream.h>

void setup()
{
Serial.begin(115200);
delay(2000);
uint8_t myvar[] = {25, 4};
uint8_t a_foo;
a_foo = myvar[0];
Serial << a_foo << endl;

++*myvar;
a_foo = myvar[0];
Serial << a_foo << endl;

uint8_t* p_foo;
p_foo = myvar;
Serial << p_foo << endl;

char grt[] = "hello";
char* x;
x = grt;
Serial << x << endl;

uint8_t* foo;
foo = &myvar[0];
Serial << *foo << endl;

}

void loop() {
  // put your main code here, to run repeatedly:
}