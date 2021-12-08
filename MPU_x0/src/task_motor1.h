/** @file task_motor1.h
 *  This file contains code for a function that gets the frequency
 *  from fft_values_x and drives motor 1 with it to control roll
 * 
 *  @author Tatum Yee & Sydney Lewis
 *  @date 2 Dec 2021
 */

#include <Arduino.h>
#include <PrintStream.h>

#ifndef TASK_MOTOR1_H
#define TASK_MOTOR1_H

// Task which gets frequency from fft_values_x share and uses it to drive motor 1 to control roll
void task_motor1(void* p_params);

#endif
