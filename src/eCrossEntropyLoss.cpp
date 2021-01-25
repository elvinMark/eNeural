#include <iostream>
#include <math.h>
#include <eMath.hpp>
#include <eNeural.hpp>

using namespace std;
using namespace emath;

double enn::eCrossEntropyLoss::loss(eMatrix* out, eMatrix* target){
  this->tmp_err = target->divides(out)->times(-1);
  return target->times(out->applyFunc(log))->sum()*-1;
}

eMatrix* enn::eCrossEntropyLoss::grad_loss(){
  return this->tmp_err;
}
