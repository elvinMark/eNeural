#include <iostream>
#include <math.h>
#include <eMath.hpp>
#include <eNeural.hpp>

using namespace std;
using namespace emath;

double criteria(double x){
  return x>0?1:0;
}

enn::eDropout::eDropout(double p){
  this->p = p;
  this->alpha = 1.0/(1.0 - p);
}
eMatrix* enn::eDropout::forward(eMatrix* inp){
  this->tmp_in = inp;
  this->mask = new eMatrix(inp->rows,inp->cols);
  this->mask->random();
  this->mask = this->mask->minus(this->p);
  this->mask = this->mask->applyFunc(criteria);
  this->tmp_out = this->mask->times(inp)->times(this->alpha);
  return this->tmp_out;
}

eMatrix* enn::eDropout::backward(eMatrix* err){
  this->tmp_err = err;
  return err->times(this->mask)->times(this->alpha);
}

void enn::eDropout::update(double learing_rate){

}

void enn::eDropout::load(FILE* p){

}

void enn::eDropout::save(FILE* p){

}
