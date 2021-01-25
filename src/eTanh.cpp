#include <iostream>
#include <math.h>
#include <eMath.hpp>
#include <eNeural.hpp>

using namespace std;
using namespace emath;

double tanh(double x){
  return (1 - exp(-x))/(1 + exp(-x));
}

double diff_tanh(double x){
  return (1 - x*x)/2.0;
}

eMatrix* enn::eTanh::forward(eMatrix* inp){
  this->tmp_in = inp;
  this->tmp_out = inp->applyFunc(tanh);
  return this->tmp_out;
}

eMatrix* enn::eTanh::backward(eMatrix* err){
  this->tmp_err = err;
  return err->times(this->tmp_out->applyFunc(diff_tanh));
}

void enn::eTanh::update(double learing_rate){

}
