/** @file shares.h
 *  This file contains external declarations of shares
 *  and queues which are used in more than one file of
 *  a tremor mug project
 * 
 *  @author Tatum Yee & Sydney Lewis
 *  @date 2 Dec 2021 
 */

#ifndef SHARES_H
#define SHARES_H

#include <taskqueue.h>
#include <taskshare.h>
#include <PrintStream.h>

/** @brief A share which holds a counter of how many times a simulated event occured */
extern Share<bool> begin_recording;

/** @brief A queue that holds 256 positions in the x direction that's taken by a measurement task */
extern Queue<float> data_queue_pos_x;

/** @brief A queue that holds 256 positions in the y direction that's taken by a measurement task */
extern Queue<float> data_queue_pos_y;

/** @brief A queue that holds 256 angular velocity measurements in the x direction that's taken by a measurement task */
extern Queue<float> data_queue_ang_vel_x;

/** @brief A queue that holds 256 angular velocity measurements in the y direction that's taken by a measurement task */
extern Queue<float> data_queue_ang_vel_y;


/** @brief A share that holds 256 angular velocity measurements in the x direction in an array */
extern Share<float> data_share_ang_vel_x;

/** @brief A share that holds 256 angular velocity measurements in the y direction in an array */
extern Share<float> data_share_ang_vel_y;

/** @brief A share that holds 256 x position measurements in an array */
extern Share<float> data_share_pos_x;

/** @brief A share that holds 256 y position measurements in an array */
extern Share<float> data_share_pos_y;


/** @brief A share that holds a frequency that motor 1 will run at to counter tremor along x axis */
extern Share<float> fft_values_x; //For motor1
/** @brief A share that holds a frequency that motor 2 will run at to counter tremor along y axis */
extern Share<float> fft_values_y; //For motor2

#endif