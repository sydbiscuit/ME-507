/** @file main.cpp
 *  This file contains the queues and shares implementation of all 
 *  classes and functions used in the tremor mug project. There are 
 *  five tasks - (1) Puts IMU data into queue (2) Takes data from
 *  queue and put it into an array to be analyzed (3) Position and
 *  Angular Velocity get passed through Fourier Transform to get 
 *  frequency (4) Frequency is used by motor 1 (5) Frequency is used
 *  by motor 2.
 *  
 *  @author Tatum Yee & Sydney Lewis
 *  @date 6 Dec 2021
 * 
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <STM32FreeRTOS.h>
#include <Wire.h>

#include <shares.h>
#include <task_get_data.h>
#include <task_put_in_array.h>
#include <task_fft.h>
#include <task_motor1.h>
#include <task_motor2.h>

// Initializes Adafruit's MPU6050 sensor 
Adafruit_MPU6050 mpu;

// A queue that holds 256 positions in the x direction that's taken by a measurement task
Queue<float> data_queue_pos_x(256, "pos_x");
// A queue that holds 256 positions in the y direction that's taken by a measurement task
Queue<float> data_queue_pos_y(256, "pos_x");
// A queue that holds 256 angular velocity measurements in the x direction that's taken by a measurement task
Queue<float> data_queue_ang_vel_x(256, "ang_vel_x");
// A queue that holds 256 angular velocity measurements in the y direction that's taken by a measurement task
Queue<float> data_queue_ang_vel_y(256, "ang_vel_y");

// A share that holds 256 angular velocity measurements in the x direction in an array
Share<float> data_share_ang_vel_x("ang_vel_x");
// A share that holds 256 angular velocity measurements in the y direction in an array
Share<float> data_share_ang_vel_y("ang_vel_y");
// A share that holds 256 x position measurements in an array
Share<float> data_share_pos_x("pos_x");
// A share that holds 256 y position measurements in an array
Share<float> data_share_pos_y("pos_y");

// A share that holds a frequency that motor 1 will run at to counter tremor along x axis
Share<float> fft_values_x("fft_x");
// A share that holds a frequency that motor 2 will run at to counter tremor along y axis
Share<float> fft_values_y("fft_y");

/** @brief Task which controls when data is taken
 *  @details Code from Professor Ridgely 
 *           "https://canvas.calpoly.edu/courses/57860/files/5533517?wrap=1"
 *  @param p_params An unused pointer to nonexistent parameters
 */
void task_control(void* p_params)
{
  for(;;)
  {
    // Tells recording task to begin
    begin_recording.put(true);
    // Waits 10 seconds
    vTaskDelay(10000);
  }
}

/** @brief Sets up hardware and creates Tasks
 *  @details Initializes serial communication, sets up pins for 
 *           motor control, sets up IMU, and creates five tasks
 */
void setup() {
    // Starts the serial port 
    Serial.begin(115200);
    // Connect ESC 1 signal wire to pin PC_7
    // Make that pin an output PWM signal
    pinMode(PC7, OUTPUT);
    // Connect ESC 2 signal wire to pin PA_9
    // Make that pin an output PWM signal
    pinMode(PA9, OUTPUT);
    // set 8-bit timer channel
    analogWriteResolution(8);
    // potValue(13) stop signal, potValue(26) max RPM
    uint8_t potValue = 13;
    // Commands motor 1 to spin/stop
    analogWrite(PC7, potValue);
    // Commands motor 2 to spin/stop
    analogWrite(PA9, potValue);

    //analogWriteFrequency(50);
    Serial << "first time "<<potValue<<endl;
    delay(1);

    // Code (lines 97-122) from Adafruit MPU6050
    // https://github.com/sydbiscuit/ME-507/blob/main/MPU6050/src/main.cpp
    while (!Serial)
    {
      delay(10); //will pause Zero, Leonardo, etc until serial console opens
    }
    
    // Try to initialize!
    if (!mpu.begin())
    {
      Serial.println("Failed to find MPU6050 chip");
      while (1)
      {
        delay(10);
      }
    }

    // Sets up MPU
    mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    Serial.print("");
    delay(100);

    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    
    // Initialize the recording share to indicate we're not taking data yet
    // From Professor Ridgely's program
    begin_recording.put(false);

    // Creates a task that records IMU data and puts it into queues
    xTaskCreate(task_get_data,          // Function
                "IMU DATA IN QUEUE",    // Name
                1024,                   // Stack Size
                NULL,                   // Paramters
                5,                      // Priority
                NULL);                  // Handle

    // Creates a task that puts IMU data into arrays
    xTaskCreate(task_put_in_array,      // Function
                "IMU DATA IN ARRAY",    // Name
                1024,                   // Stack Size
                NULL,                   // Parameters
                4,                      // Piority
                NULL);                  // Handle
    
    // Creates a task that passes positions and angular velocities to get a frequency
    xTaskCreate(task_fft,               // Function
                "DATA FFT ANALYSIS",    // Name
                1024,                   // Stack Size
                NULL,                   // Parameters
                3,                      // Priority
                NULL);                  // Handle

    // Creates a task that gives motor 1 a frequency to spin at to counter hand tremor
    xTaskCreate(task_motor1,            // Function
                "MOTOR 1",              // Name
                1024,                   // Stack Size
                NULL,                   // Parameters
                2,                      // Priority
                NULL);                  // Handle

    // Creates a task that gives motor 2 a frequency to spin at to counter hand tremor
    xTaskCreate(task_motor2,            // Function
                "MOTOR 2",              // Name
                1024,                   // Stack Size
                NULL,                   // Parameters
                2,                      // Priority
                NULL);                  // Handle


}

void loop() {
  // put your main code here, to run repeatedly:
}