#include <iostream>
#include "eMath.hpp"
#include "eNeural.hpp"

using namespace std;
using namespace emath;

double enn::eMeanSquareLoss::loss(eMatrix* out, eMatrix* target){
  this->tmp_err = out->minus(target);
  return this->tmp_err->times(this->tmp_err)->sum()/2;
}

eMatrix* enn::eMeanSquareLoss::grad_loss(){
  return this->tmp_err;
}
