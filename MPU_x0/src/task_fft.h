//   fft.h - declaration of class
//   of fast Fourier transform - FFT
//
//   The code is property of LIBROW
//   You can use it on your own
//   When utilizing credit LIBROW site

#ifndef _FFT_H_
#define _FFT_H_

#include "complex.h"

class CFFT
{
public:
   //   FORWARD FOURIER TRANSFORM
   //     Input  - input data
   //     Output - transform result
   //     N      - length of both input data and result
   static bool Forward(const complex *const Input, complex *const Output,
      const unsigned int N);

   
   //   FFT implementation
   static void Perform(complex *const Data, const unsigned int N,
      const bool Inverse = false);

};

#endif