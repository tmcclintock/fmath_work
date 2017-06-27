#include <cmath>
#include "/home/tom/code/fmath/fmath.hpp"
#include "comp.h"
#include <iostream>

extern "C" float fexpf(float x){
  return fmath::exp(x);
}

extern "C" float cexpf(float x){
  return std::exp(x);
}

extern "C" double fexpd(double x){
  return fmath::expd(x);
}

extern "C" double cexpd(double x){
  return std::exp(x);
}

extern "C" double*fexpd_v(double*x, int n){
  /*This is the vector form from fmath.
    This is the one that offers the most speed up,
    and is what we will look to put into ngmix.
   */
  fmath::expd_v(x, (size_t)n);
  return x;
}
