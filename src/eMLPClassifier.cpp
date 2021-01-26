#include <iostream>
#include <vector>
#include <math.h>
#include <eMath.hpp>
#include <eNeural.hpp>

using namespace std;
using namespace emath;

enn::eMLPClassifier::eMLPClassifier(std::vector<int> structure,int act_fun) {
  for(int i = 0;i<structure.size()-1;i++){
    this->add(new eLinear(structure[i],structure[i+1]));
    if(act_fun == enn::SIGMOID)
      this->add(new eSigmoid());
    else if(act_fun == enn::TANH)
      this->add(new eTanh());
    else if(act_fun == enn::RELU)
      this->add(new eReLU());
  }
  this->add(new eSoftmax());
}

void enn::eMLPClassifier::train(eMatrix* inp,eMatrix *out, double learning_rate, int maxIt){
  this->enn::eSequential::train(inp,out,new eCrossEntropyLoss(),learning_rate,maxIt);
}
