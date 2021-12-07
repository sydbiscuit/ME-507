#include <Arduino.h>
#include <PrintStream.h>

/**
*class motor1
* {
*    protected:
*        uint16_t frequency;
*        uint16_t delay;
*
*    public:
*        Motor1(void);
*        void make_motor_spin(float freq);
* };
*/

#ifndef TASK_MOTOR1_H
#define TASK_MOTOR_H

void motor1(void* p_params);

#endif
