#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comp.h"

int main(){

  clock_t begin;
  clock_t end;
  double time;
  int i,n = 100000;
  double*x = (double*)malloc(n*sizeof(double));
  for(i=0; i < n; i++)
    x[i] = (double)i/n;

  begin = clock();
  fexpd_v(x, n);
  end = clock();
  time = (double)(end-begin)/CLOCKS_PER_SEC;
  printf("expd_v time is %e\n",time);

  //reset x
  for(i=0; i < n; i++)
    x[i] = (double)i/n;

  begin = clock();
  for(i=0; i < n; i++)
    x[i] = fexpd(x[i]);
  end = clock();
  time = (double)(end-begin)/CLOCKS_PER_SEC;
  printf("fmath::expd time is %e\n",time);


  //reset x
  for(i=0; i < n; i++)
    x[i] = (double)i/n;

  begin = clock();
  for(i=0; i < n; i++)
    x[i] = cexpd(x[i]);
  end = clock();
  time = (double)(end-begin)/CLOCKS_PER_SEC;
  printf("std::expd time is %e\n",time);


  free(x);
  return 0;

}
