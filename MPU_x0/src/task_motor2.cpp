/** @file task_motor2.cpp
 *  This file contains the code for a task which takes the
 *  frequency from task_fft.cpp and uses it to set the 
 *  motor 2 frequency, which controls movement in the y
 *  direction (pitch)
 *  
 *   @author Tatum Yee & Sydney Lewis
 *   @date 6 Dec 2021
 */
#include <Arduino.h>
#include <PrintStream.h>
#include <STM32FreeRTOS.h>
//#include <data.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <iostream>

#include <task_motor2.h>
#include <shares.h>

/** @brief Task that takes the frequency from the 
 *         fft_values_y shares and uses it to set
 *         the frequency of motor 2
 *  @details Controls pitch
 *  @param p_params An unused pointer to nonexistent parameters
 */
void task_motor2(void* p_params)
{
    float frequency = 0;

    for (;;)
    {
        // Assigns frequency to the frequency value that was previously put into the fft_values_x share
        frequency = fft_values_y.get();
        // Writes the frequency grabbed from the share to motor 2
        analogWriteFrequency(frequency);
        // Waits 0.1 seconds
        vTaskDelay(100);
    }

}
