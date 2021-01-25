#include <iostream>
#include <math.h>
#include "eMath.hpp"
#include "eNeural.hpp"

using namespace std;
using namespace emath;
using namespace enn;

class myNN{
public:
  eLinear* fc1;
  eTanh* sig1;
  eLinear* fc2;
  eReLU* sig2;
  eSoftmax* soft;
  myNN(){
    fc1 = new eLinear(2,5);
    sig1 = new eTanh();
    fc2 = new eLinear(5,2);
    sig2 = new eReLU();
    soft = new eSoftmax();
  }
  eMatrix* forward(eMatrix* inp){
    eMatrix* tmp;
    tmp = fc1->forward(inp);
    tmp = sig1->forward(tmp);
    tmp = fc2->forward(tmp);
    tmp = sig2->forward(tmp);
    tmp = soft->forward(tmp);
    return tmp;
  }
  eMatrix* backward(eMatrix* err){
    eMatrix* tmp;
    tmp = soft->backward(err);
    tmp = sig2->backward(tmp);
    tmp = fc2->backward(tmp);
    tmp = sig1->backward(tmp);
    tmp = fc1->backward(tmp);
    return tmp;
  }
  void update(double learning_rate){
    fc1->update(learning_rate);
    sig1->update(learning_rate);
    fc2->update(learning_rate);
    sig2->update(learning_rate);
    soft->update(learning_rate);
  }
  void train(eMatrix* inp,eMatrix* target,double learning_rate,int maxIt){
    eMatrix* tmp;
    double curr_loss;
    //eMeanSquareLoss* loss = new eMeanSquareLoss();
    eCrossEntropyLoss* loss = new eCrossEntropyLoss();
    for(int i = 0;i<maxIt;i++){
      tmp = forward(inp);
      curr_loss = loss->loss(tmp,target);
      cout << "Loss: " << curr_loss << endl;
      backward(loss->grad_loss());
      update(learning_rate);
    }
  }
};


int  main(){
  double in_data[8] = {0,0,0,1,1,0,1,1};
  double out_data[8] = {1,0,0,1,0,1,1,0};
  eMatrix* inp,*out;
  myNN *nn = new myNN();
  inp = new eMatrix(4,2);
  out = new eMatrix(4,2);
  inp->data = in_data;
  out->data = out_data;
  cout << nn->forward(inp) << endl;
  nn->train(inp,out,0.001,1000);
  cout << nn->forward(inp) << endl;
}
