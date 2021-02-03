#include <eMath.hpp>

#ifndef E_DATA
#define E_DATA
using namespace emath;

eMatrix** generate_data(int N){
  eMatrix** out;
  double m,b,x,y;
  srand(time(NULL));
  m = (rand()%1000)/1000.0;
  b = (rand()%1000)/1000.0;
  out = (eMatrix**) malloc(sizeof(eMatrix*)*2);
  out[0] = new eMatrix(N,2);
  out[1] = new eMatrix(N,2);
  out[0]->random();
  for(int i = 0;i<N;i++){
    x = out[0]->data[2*i];
    y = out[0]->data[2*i+1];
    x = 5*x - 2.5;
    y = 5*y - 2.5;
    out[0]->data[2*i] = x;
    out[0]->data[2*i+1] = y;
    out[1]->data[2*i] = (m*x + b)>y?1:0;
    out[1]->data[2*i+1] = (m*x + b)>y?0:1;
  }
  return out;
}
#endif
