#include <cmath>
#include <iostream>
#include <ctime>
#include <smmintrin.h>

#include "/home/tom/code/fmath/fmath.hpp"

int main(){
  clock_t begin = clock();
  float x = 3.0;
  int i;
  int N = 10000000;
  std::scientific;
  for(i=N; i > 0; i--)
    std::exp((float)i*x);
  clock_t end = clock();
  std::cout << "std::exp(x):   " << double(end-begin)/CLOCKS_PER_SEC << "\n";

  std::scientific;
  begin = clock();
  for(i=N; i > 0; i--)
    fmath::exp((float)i*x);
  end = clock();
  std::cout << "fmath::exp(x): " << double(end-begin)/CLOCKS_PER_SEC << "\n";

  std::cout << std::exp(x) << "\n";
  std::cout << fmath::exp(x) << "\n";
}
