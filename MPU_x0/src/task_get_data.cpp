/** @file task_get_data.cpp
 *  This file contains code for a task which
 *  records data
 *  
 *  @author Tatum Yee & Sydney Lewis
 *  @date 2 Dec 2021
 */
   
#include <Arduino.h>
#include <PrintStream.h>
#include <STM32FreeRTOS.h>
//#include <data.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <iostream>
#include <Wire.h>

#include <shares.h>
#include <task_get_data.h>

// Number of data points taken in one set one data set
const uint16_t num_points = 12;

Adafruit_MPU6050 mpu;

/** @brief Task which takes some data and stuffs it into a queue
 *  @param p_params An unused pointer to nonexistent parameters
 */

void task_get_data(void* p_params)
{
    // State machine takes data or doesn't
    uint8_t state = 0;
    // Counts number of data points recorded
    uint16_t counter;
    
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    for (;;)
    {
        // In state 0, we wait for signal from control task to take data
        if (state == 0)
        {
            if (begin_recording.get())
            {
                begin_recording.put(false);  // What does this line mean...why false
                counter = 0;
                state = 1;
            }
        }
        else if (state == 1)
        {
            // Read positions and angular velocity in x and y direction
            data_queue.put(g.gyro.x);
            data_queue.put(g.gyro.y);
            data_queue.put(a.acceleration.x);
            data_queue.put(a.acceleration.y);

            if (++counter > counter)
            {
                state = 0;
            }
        }
    }
        

}