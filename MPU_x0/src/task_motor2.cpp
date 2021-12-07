#include <Arduino.h>
#include <PrintStream.h>
#include <STM32FreeRTOS.h>
//#include <data.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <iostream>

#include <task_motor2.h>
#include <shares.h>

int potValue;

void task_motor2(void* p_params)
{
    float frequency = 0;

    for (;;)
    {
        frequency = fft_values_y.get();
        analogWriteFrequency(frequency);
        vTaskDelay(100);
    }

}
