#include <iostream>
#include <math.h>
#include <eMath.hpp>
#include <eNeural.hpp>

using namespace std;
using namespace emath;

double sigmoid(double x){
  return 1/(1 + exp(-x));
}

double diff_sigmoid(double x){
  return x*(1-x);
}

eMatrix* enn::eSigmoid::forward(eMatrix* inp){
  this->tmp_in = inp;
  this->tmp_out = inp->applyFunc(sigmoid);
  return this->tmp_out;
}

eMatrix* enn::eSigmoid::backward(eMatrix* err){
  this->tmp_err = err;
  return err->times(this->tmp_out->applyFunc(diff_sigmoid));
}

void enn::eSigmoid::update(double learing_rate){

}

void enn::eSigmoid::load(FILE* p){

}

void enn::eSigmoid::save(FILE* p){

}
