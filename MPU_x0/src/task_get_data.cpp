/** @file task_get_data.cpp
 *  This file contains code for a task which records IMU data
 *  and puts it into four queues. (1) x - Position (2) y - Position
 *  (3) x - Angular Velocity (4) y - Angular Velocity
 * 
 *  Modeled after Professor Ridgely's example task_take_data.cpp code: 
 *  https://canvas.calpoly.edu/courses/57860/files/5533521?wrap=1
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

/** @brief Number of data points taken in one set one data set */
const uint16_t num_points = 256;

/** @brief Initializing MPU */
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
    
    // Initializes MPU variables needed
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    for (;;)
    {
        // In state 0, we wait for signal from control task to take data
        if (state == 0)
        {
            if (begin_recording.get())
            {
                begin_recording.put(false);
                counter = 0;
                state = 1;
            }
        }
        // In state 1, we take data and put it into a queue
        else if (state == 1)
        {
            // Read positions and angular velocity in x and y direction
            data_queue_ang_vel_x.put(g.gyro.x);
            data_queue_ang_vel_y.put(g.gyro.y);
            data_queue_pos_x.put(a.acceleration.x);
            data_queue_pos_y.put(a.acceleration.y);
            
            // If queue is full, state returns to zero
            if (++counter > num_points)
            {
                state = 0;
            }
        }
        // Runs every 0.1 seconds
        vTaskDelay(100);
    }
}