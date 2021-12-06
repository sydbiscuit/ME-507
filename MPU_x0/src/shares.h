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

// A share which holds a counter of how many times a 
// simulated event occured 
extern Share<bool> begin_recording;

// A queue which triggers a task to print the count
// at certain times
extern Queue<float> data_queue_pos_x(256, "pos_x");
extern Queue<float> data_queue_pos_y(256, "pos_x");
extern Queue<float> data_queue_ang_vel_x(256, "ang_vel_x");
extern Queue<float> data_queue_ang_vel_y(256, "ang_vel_y");

#endif