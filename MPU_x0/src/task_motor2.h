/** @file task_motor2.h
 *  This file contains code for a function that gets the frequency
 *  from fft_values_y and drives motor 2 with it to control pitch
 * 
 *  @author Tatum Yee & Sydney Lewis
 *  @date 2 Dec 2021
 */

#include <Arduino.h>
#include <PrintStream.h>


#ifndef TASK_MOTOR2_H
#define TASK_MOTOR2_H

// Task which gets frequency from fft_values_y share and uses it to drive motor 2 to control pitch
void task_motor2(void* p_params);

#endif
