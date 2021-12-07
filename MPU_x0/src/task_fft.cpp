//   fft.cpp - implementation of class
//   of fast Fourier transform - FFT
//
//   The code is property of LIBROW
//   You can use it on your own
//   When utilizing credit LIBROW site

//   Include declaration file
#include "task_fft.h"
//   Include math library
#include <math.h>

#include <Arduino.h>
#include <task_get_data.h>
#include <I2Cdev.h>
#include <task_put_in_array.h>
#include <STM32FreeRTOS.h>
#include <shares.h>

float pos_x[256];
float pos_y[256];

//   FORWARD FOURIER TRANSFORM
//     Input  - input data
//     Output - transform result
//     N      - length of both input data and result
bool task_fft::Forward(const complex *const Input, complex *const Output,
   const unsigned int N)
{
   //   Check input parameters
   if (!Input || !Output || N < 1 || N & (N - 1))
      return false;
   //   Initialize data
   Rearrange(Input, Output, N);
   //   Call FFT implementation
   Perform(Output, N);
   //   Succeeded
   return true;
}


//   FFT implementation
void task_fft::Perform(complex *const Data, const unsigned int N,
   const bool Inverse /* = false */)
{
   const double pi = Inverse ? 3.14159265358979323846 : -3.14159265358979323846;
   //   Iteration through dyads, quadruples, octads and so on...
   for (unsigned int Step = 1; Step < N; Step <<= 1)
   {
      //   Jump to the next entry of the same transform factor
      const unsigned int Jump = Step << 1;
      //   Angle increment
      const double delta = pi / double(Step);
      //   Auxiliary sin(delta / 2)
      const double Sine = sin(delta * .5);
      //   Multiplier for trigonometric recurrence
      const complex Multiplier(-2. * Sine * Sine, sin(delta));
      //   Start value for transform factor, fi = 0
      complex Factor(1.);
      //   Iteration through groups of different transform factor
      for (unsigned int Group = 0; Group < Step; ++Group)
      {
         //   Iteration within group 
         for (unsigned int Pair = Group; Pair < N; Pair += Jump)
         {
            //   Match position
            const unsigned int Match = Pair + Step;
            //   Second term of two-point transform
            const complex Product(Factor * Data[Match]);
            //   Transform for fi + pi
            Data[Match] = Data[Pair] - Product;
            //   Transform for fi
            Data[Pair] += Product;
         }
         //   Successive transform factor via trigonometric recurrence
         Factor = Multiplier * Factor + Factor;
      }
   }
}
