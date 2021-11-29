#include <Arduino.h>
#include <cmath>

#ifndef _STAT_TRACKER_H_
#define _STAT_TRACKER_H_

class StatTracker
{
    protected:
        float sum;
        float square;
        uint32_t numb_points;
        float avg;
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
