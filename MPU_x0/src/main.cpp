/** @file main.cpp
 *  This file contains the implementation of all classes and functions
 *  used in the tremor mug project. 
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


Adafruit_MPU6050 mpu;

Queue<float> data_queue_pos_x(256, "pos_x");
Queue<float> data_queue_pos_y(256, "pos_x");
Queue<float> data_queue_ang_vel_x(256, "ang_vel_x");
Queue<float> data_queue_ang_vel_y(256, "ang_vel_y");

Share<float> data_share_ang_vel_x("pos_x");
Share<float> data_share_ang_vel_y("pos_y");
Share<float> data_share_pos_x("ang_vel_x");
Share<float> data_share_pos_y("ang_vel_y");

Share<float> fft_values_x("fft_x"); //For motor1
Share<float> fft_values_y("fft_y"); //For motor2

void setup() {

    Serial.begin(115200);
    pinMode(PC7, OUTPUT);
    pinMode(PA9, OUTPUT);
    analogWriteResolution(8);
    uint8_t potValue = 13;
    analogWrite(PC7, potValue);
    analogWrite(PA9, potValue);

    //analogWriteFrequency(50);
    Serial << "first time "<<potValue<<endl;
    delay(1);

    while (!Serial)
    {
      delay(10);
    }

    if (!mpu.begin())
    {
      Serial.println("Failed to find MPU6050 chip");
      while (1)
      {
        delay(10);
      }
    }

    mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    Serial.print("");
    delay(100);

    xTaskCreate(task_get_data,
                "IMU DATA IN QUEUE",
                1024,
                NULL,
                5,
                NULL);

    xTaskCreate(task_put_in_array,
                "IMU DATA IN ARRAY",
                1024,
                NULL,
                4,
                NULL);

    xTaskCreate(task_fft,
                "DATA FFT ANALYSIS",
                1024,
                NULL,
                3,
                NULL);

    xTaskCreate(task_motor1,
                "MOTOR 1",
                1024,
                NULL,
                2,
                NULL);

    xTaskCreate(task_motor2,
                "MOTOR 2",
                1024,
                NULL,
                2,
                NULL);


    






}

void loop() {
  // put your main code here, to run repeatedly:
}