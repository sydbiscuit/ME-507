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

// A share which holds a counter of how many times a 
// simulated event occured 
extern Share<bool> begin_recording;

// A queue which triggers a task to print the count
// at certain times
extern Queue<float> data_queue_pos_x;
extern Queue<float> data_queue_pos_y;
extern Queue<float> data_queue_ang_vel_x;
extern Queue<float> data_queue_ang_vel_y;

extern Share<float> data_share_ang_vel_x;
extern Share<float> data_share_ang_vel_y;
extern Share<float> data_share_pos_x;
extern Share<float> data_share_pos_y;

extern Share<float> fft_values_x; //For motor1
extern Share<float> fft_values_y; //For motor2

#endif