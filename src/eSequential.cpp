#include <iostream>
#include <vector>
#include <math.h>
#include <eMath.hpp>
#include <eNeural.hpp>

using namespace std;
using namespace emath;

void enn::eSequential::add(eLayer* layer){
  this->layers.push_back(layer);
}

eMatrix* enn::eSequential::forward(eMatrix* inp){
  eMatrix* tmp;
  tmp = inp;
  for(int i = 0;i<this->layers.size();i++)
    tmp = this->layers[i]->forward(tmp);
  return tmp;
}

eMatrix* enn::eSequential::backward(eMatrix* err){
  eMatrix* tmp;
  tmp = err;
  for(int i = this->layers.size() - 1;i>=0;i--)
    tmp = this->layers[i]->backward(tmp);
  return tmp;
}

void enn::eSequential::update(double learning_rate){
  for(int i = 0;i<this->layers.size();i++)
    this->layers[i]->update(learning_rate);
}

void enn::eSequential::train(eMatrix* inp,eMatrix *out, eLoss *loss, double learning_rate, int maxIt){
  eMatrix* tmp;
  for(int i = 0;i<maxIt;i++){
    tmp = this->forward(inp);
    loss->loss(tmp,out);
    this->backward(loss->grad_loss());
    this->update(learning_rate);
  }
}
