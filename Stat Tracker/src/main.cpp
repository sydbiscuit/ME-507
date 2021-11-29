#include <PrintStream.h>
#include <stat_tracker.h>
#include <Arduino.h>


void setup() 
{
  float num;
  num = 42.2;
  float answer;
  StatTracker my_stats;
  my_stats.add_data(num);
  
  
  answer = my_stats.average();


  Serial << answer << endl;




}

void loop() {
  // put your main code here, to run repeatedly:
}