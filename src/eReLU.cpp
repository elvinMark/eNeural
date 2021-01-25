#include <iostream>
#include <math.h>
#include <eMath.hpp>
#include <eNeural.hpp>

using namespace std;
using namespace emath;

double relu(double x){
  return x>0?x:0.001*x;
}

double diff_relu(double x){
  return x>0?1:0.001;
}

eMatrix* enn::eReLU::forward(eMatrix* inp){
  this->tmp_in = inp;
  this->tmp_out = inp->applyFunc(relu);
  return this->tmp_out;
}

eMatrix* enn::eReLU::backward(eMatrix* err){
  this->tmp_err = err;
  return err->times(this->tmp_out->applyFunc(diff_relu));
}

void enn::eReLU::update(double learing_rate){

}
