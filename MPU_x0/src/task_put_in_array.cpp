/** @file task_put_in_array.cpp
 *  This file contains a task which takes data from the task
 *  in task_get_data and put it in an array
 * 
 *  @author Tatum Yee & Sydney Lewis
 *  @date 2 Dec 2021
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <STM32FreeRTOS.h>

#include <task_get_data.h>
#include <shares.h>

/** @brief Task that takes data collected in queue and puts it
 *         into an array
 *  @details Each data measurement type will have it's own array.
 *           There will be four arrays, one for x-position, one for 
 *           y-position, one for angular velocity in x direction, and
 *           one for angular velocity in the y direction.
 *  @param p_params An unused pointer to nonexistent parameters
 */
void task_put_in_array (void* p_params)
{
    //Counts data points to be displayed
    uint32_t counter = 0;

    // Holds a data point from pos_x queue
    float data_point_pos_x;
    // Holds a data point from pos_x queue
    float data_point_pos_y;
    // Holds a data point from ang_vel_x queue
    float data_point_ang_vel_x;
    // Holds a data point from ang_vel_y queue
    float data_point_ang_vel_y;

    // Creates an array for x-dir angular velocity measurements from IMU
    float mpu_data_acc_x[256];
    // Creates an array for y-dir angular velocity measurements from IMU
    float mpu_data_acc_y[256];
    // Creates an array for x-position measurements from IMU
    float mpu_data_g_x[256];
    // Creates an array for y-position measurements from IMU
    float mpu_data_g_y[256];

    for(;;)
    {
        // Fills up each array with 256 data points
        for (counter = 0; counter < 256; counter++)
        {
            // Goes through queue to get each x position taken by IMU
            data_point_pos_x = data_queue_ang_vel_x.get();
            // Goes through queue to get each y position taken by IMU
            data_point_pos_y = data_queue_ang_vel_y.get();
            // Goes through queue to get each angular velocity measurement in x direction taken by IMU
            data_point_ang_vel_x = data_queue_pos_x.get();
            // Goes through queue to get each angular velocity measurement in x direction taken by IMU
            data_point_ang_vel_y = data_queue_pos_y.get();

            // Puts each x position taken by IMU into an array
            mpu_data_g_x[counter] = data_point_pos_x;
            // Puts each y position taken by IMU into an array
            mpu_data_g_y[counter] = data_point_pos_y;
            // Puts each angular velocity measurement in x direction taken by IMU into an array
            mpu_data_acc_x[counter] = data_point_ang_vel_x;
            // Puts each angular velocity measurement in y direction taken by IMU into an array
            mpu_data_acc_y[counter] = data_point_ang_vel_y;
        }
    }
}

