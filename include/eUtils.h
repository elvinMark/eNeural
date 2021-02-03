#include <stdio.h>
#include <eMath.hpp>
#include <time.h>

#ifndef E_UTILS
#define E_UTILS

double get_next_value(FILE* p){
  int i;
  double d;
  unsigned char* c = (unsigned char*)&d;
  for(i = 0;i<8;i++)
    c[i] = getc(p);
  return d;
}
#endif
