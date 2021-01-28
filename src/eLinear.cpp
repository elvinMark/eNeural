#include <iostream>
#include <eNeural.hpp>
#include <eMath.hpp>
#include <stdio.h>

using namespace std;
using namespace emath;

enn::eLinear::eLinear(int num_inputs,int num_outputs){
  this->W = new eMatrix(num_inputs,num_outputs);
  this->b = new eMatrix(1,num_outputs);
  srand (time(NULL));
  this->W->random();
  this->b->random();
}

eMatrix* enn::eLinear::forward(eMatrix* inp){
  this->tmp_in = inp;
  this->tmp_out = inp->dot(this->W)->plus(this->b);
  return this->tmp_out;
}

eMatrix* enn::eLinear::backward(eMatrix* err){
  this->tmp_err = err;
  return err->dot(this->W->transpose());
}

void enn::eLinear::update(double learning_rate){
  eMatrix* delta;
  delta = this->tmp_in->transpose()->dot(this->tmp_err);
  this->W = this->W->minus(delta->times(learning_rate));
  delta = this->tmp_err->sum(1);
  this->b = this->b->minus(delta->times(learning_rate));
}

void enn::eLinear::load(FILE* p){
  this->W->load(p);
  this->b->load(p);
}

void enn::eLinear::save(FILE* p){
  this->W->save(p);
  this->b->save(p);
}

ostream& operator << (ostream& os,const enn::eLinear& nn){
  os << "Weights:\n" << nn.W << endl;
  os << "bias:\n" << nn.b << endl;
  return os;
}

ostream& operator << (ostream& os,const enn::eLinear* nn){
  os << "Weights:\n" << nn->W << endl;
  os << "bias:\n" << nn->b << endl;
  return os;
}

