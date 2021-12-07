#include <Arduino.h>
#include <PrintStream.h>
#include <STM32FreeRTOS.h>
//#include <data.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <iostream>

#include <task_motor1.h>
#include <shares.h>

int potValue;

void motor1(void* p_params)
{
    uint8_t potValue = 13;
    float frequency = 0;

    for (;;)
    {
        frequency = fft_values_x.get();
        analogWriteFrequency(frequency);
        vTaskDelay(100);
    }

}

/**
* motor1::motor1(void)
* {
*    frequency = fft_values_x_pos.get();
*    analogWriteFrequency(frequency);
* }
*/