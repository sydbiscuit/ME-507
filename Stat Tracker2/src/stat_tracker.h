/** @file stat_tracker.h
 *    This file contains the headers for a class that calculates the average
 *    and standard deviation of inputted data.
 * 
 *  @author Sydney Lewis
 *  @date  2021-Nov-6 Original file
 */


/** @brief   Class which keeps track of data and calculates the average and standard deviation.
 *  @details The class can also return the number of data points collected, as well as clear the
 *           data to recalculate with a new set.
 */



#include <Arduino.h>
#include <cmath>

#ifndef _STAT_TRACKER_H_
#define _STAT_TRACKER_H_

class StatTracker
{
    protected:
    /// The sum of all the data input
        float sum;
    /// The data squared and added together
        float square;
    /// The number of data points entered
        uint32_t numb_points;
    /// The average of the data points
        float avg;
    /// The standard deviation of the data points
        float st_dev;
    
    public:
        StatTracker(void);
        void add_data(float num);
        void add_data(int32_t num);
        void add_data(uint32_t num);
        uint32_t num_points (void);
        float average (void);
        float std_dev (void);
        void clear (void);

};


#endif 
