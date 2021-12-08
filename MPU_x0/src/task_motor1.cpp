/** @file task_motor1.cpp
 *  This file contains the code for a task which takes the
 *  frequency from task_fft.cpp and uses it to set the 
 *  motor 1 frequency, which controls movement in the x
 *  direction (roll)
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

#include <task_motor1.h>
#include <shares.h>

/** @brief Task that takes the frequency from the 
 *         fft_values_x shares and uses it to set
 *         the frequency of motor 1
 *  @details Controls roll
 *  @param p_params An unused pointer to nonexistent parameters
 */
void task_motor1(void* p_params)
{
    // Initializes frequency variable
    float frequency = 0;

    for (;;)
    {
        // Assigns frequency to the frequency value that was previously put into the fft_values_x share
        frequency = fft_values_x.get();
        // Writes the frequency grabbed from the share to motor 1
        analogWriteFrequency(frequency);
        // Waits 0.1 seconds
        vTaskDelay(100);
    }

}
