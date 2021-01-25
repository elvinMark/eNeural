#include <iostream>
#include <math.h>
#include "eMath.hpp"
#include "eNeural.hpp"

using namespace std;
using namespace emath;

eMatrix* enn::eSoftmax::forward(eMatrix* inp){
  eMatrix* tmp_exp, *acc_exp;
  this->tmp_in = inp;
  tmp_exp = inp->applyFunc(exp);
  acc_exp = tmp_exp->sum(0);
  this->tmp_out = tmp_exp->divides(acc_exp);
  return this->tmp_out;
}

eMatrix* enn::eSoftmax::backward(eMatrix* err){
  eMatrix* tmp;
  this->tmp_err = err;
  tmp = err->times(this->tmp_out);
  return tmp->minus(this->tmp_out->times(tmp));
}

void enn::eSoftmax::update(double learing_rate){

}
