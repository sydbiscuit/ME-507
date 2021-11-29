#include <PrintStream.h>
#include <stat_tracker.h>
#include <Arduino.h>


void setup() 
{
  Serial.begin(115200);
  delay(2000);
  Serial << endl << endl << "Hello, I'm awake!" << endl;


  float num;
  num = 10.0;
  float num2;
  num2 = 12.0;
  float num3;
  num3 = 23.0;
  
  float answer2;
  uint32_t answer1;
  float answer3;

  StatTracker my_stats;
  my_stats.add_data(num);
  my_stats.add_data(num2);
  my_stats.add_data(num3);
  
  
  answer1 = my_stats.num_points();
  delay(1000);
  answer2 = my_stats.average();
  delay(1000);
  answer3 = my_stats.std_dev();


  Serial << answer1 << endl;
  delay(1000);
  Serial << answer2 << endl;
  delay(1000);
  Serial << answer3 << endl;

  //my_stats.clear();
  //delay(1000);
  //Serial << answer1 << endl;




}

void loop() {
  // put your main code here, to run repeatedly:
}