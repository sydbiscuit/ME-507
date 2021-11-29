#include <stat_tracker.h>

StatTracker::StatTracker(void)
{
    
    sum = 0;
    square = 0;
    numb_points = 0;
    avg = 0;
    st_dev = 0;


}

void StatTracker:: add_data (float num)
{

    sum+=num;
    square += pow(num,2);   // computes the square of the number and adds it to the variable squares

    numb_points++;
}

void StatTracker:: add_data(int32_t num)
{
    sum+=num;

    square += pow(num,2);

    numb_points++;

}

void StatTracker:: add_data(uint32_t num)
{
    sum+=num;

    square+= pow(num,2);

    numb_points++;

}

uint32_t StatTracker:: num_points(void)
{

    return numb_points;
}

float StatTracker:: average(void)
{


    if (sum)
    {
        avg = sum/numb_points;
        return avg;
    }
    
}
