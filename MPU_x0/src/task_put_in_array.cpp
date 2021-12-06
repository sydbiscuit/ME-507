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

/** @brief Task that takes data collected in queue and put it
 *         into an array
 *  @details 
 * 
 *  @param p_params An unused pointer to nonexistent parameters
 */

void task_put_in_array (void* p_params)
{
    //Counts data points to be displayed
    uint32_t counter = 0;
    //Holds a data point from the queue
    float data_point_pos_x;
    float data_point_pos_y;
    float data_point_ang_vel_x;
    float data_point_ang_vel_y;

    float mpu_data_acc_x[256];
    float mpu_data_acc_y[256];
    float mpu_data_g_x[256];
    float mpu_data_g_y[256];

    for(;;)
    {
        for (counter = 0; counter < 256; counter++)
        {
            data_point_pos_x = data_queue_ang_vel_x.get();
            data_point_pos_y = data_queue_ang_vel_y.get();
            data_point_ang_vel_x = data_queue_pos_x.get();
            data_point_ang_vel_y = data_queue_pos_y.get();

            mpu_data_g_x[counter] = data_point_pos_x;
            mpu_data_g_y[counter] = data_point_pos_y;
            mpu_data_acc_x[counter] = data_point_ang_vel_x;
            mpu_data_acc_y[counter] = data_point_ang_vel_y;
        }
    }
}

