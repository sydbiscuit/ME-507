/** @file stat_tracker.cpp
 *    This file contains source code for a class that calculates the
 *    average and standard deviation of data input.
 * 
 *  @author Sydney Lewis
 *  @date  2021-Nov-6 Original file
 */


#include <stat_tracker.h>

/** @brief   Create a StatTracker object.
 *  @details This constructor does not require inputs.
 */
StatTracker::StatTracker(void)
{
    
    sum = 0;
    square = 0;
    numb_points = 0;
    avg = 0;
    st_dev = 0;
}

/** @brief   This function sums the data points input to the function and keeps track of how many data points are added.
 *  @param   num The data point input to the function. In this case a float data point.
 */
void StatTracker:: add_data (float num)
{
    sum+=num;
    numb_points++;
    square += pow(num,2);   // computes the square of the number and adds it to the variable square
    
}

/** @brief   This function sums the data points input to the function and keeps track of how many data points are added.
 *  @param   num The data point input to the function. In this case a signed 32-bit data point.
 */
void StatTracker:: add_data(int32_t num)
{
    sum+=num;
    square += pow(num,2);
    numb_points++;

}

/** @brief   This function sums the data points input to the function and keeps track of how many data points are added.
 *  @param   num The data point input to the function. In this case an unsigned 32-bit data point.
 */
void StatTracker:: add_data(uint32_t num)
{
    sum+=num;
    square+= pow(num,2);
    numb_points++;

}

/** @brief   This function returns the number of data points input.
 *  @returns Returns the number of data points input.  
 */
uint32_t StatTracker:: num_points(void)
{

    return numb_points;
}


/** @brief   This function returns the average of the input data points.
 *  @returns Returns the average of the data input.
 */
float StatTracker:: average(void)
{
    if (sum)
    {
        avg = sum/numb_points;
        return avg;
    }
}

/** @brief   This function returns the standard deviation of the input data points.
 *  @returns Returns the standard deviation of the data input.
 */
float StatTracker:: std_dev(void)
{

    if (sum)
    {
        float expression;
        expression = 0;
        expression = square/numb_points - pow(avg,2);
        st_dev = sqrt(expression);
        return st_dev;
    }
    
}


/** @brief   This function deletes all the data, returning to no points added state.
 */
void StatTracker:: clear (void)
{
    sum = 0;
    square = 0;
    numb_points = 0;
    avg = 0;
    st_dev = 0; 
}