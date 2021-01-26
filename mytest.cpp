#include <iostream>
#include <math.h>
#include <eMath.hpp>
#include <eNeural.hpp>
#include <vector>

using namespace std;
using namespace emath;
using namespace enn;

class myNN{
public:
  std::vector<eLayer *> layers;
  myNN(){
    layers.push_back(new eLinear(2,5));
    layers.push_back(new eReLU());
    layers.push_back(new eLinear(5,3));
    layers.push_back(new eReLU());
    layers.push_back(new eLinear(3,2));
    layers.push_back(new eReLU());
    layers.push_back(new eSoftmax());
  }
  eMatrix* forward(eMatrix* inp){
    eMatrix* tmp;
    tmp = inp;
    for(int i = 0;i<layers.size();i++)
      tmp = layers[i]->forward(tmp);
    return tmp;
  }
  eMatrix* backward(eMatrix* err){
    eMatrix* tmp;
    tmp = err;
    for(int i = layers.size() - 1;i>=0;i--)
      tmp = layers[i]->backward(tmp);
    return tmp;
  }
  void update(double learning_rate){
    for(int i = 0;i<layers.size();i++)
      layers[i]->update(learning_rate);
  }
  void train(eMatrix* inp,eMatrix* target,eLoss* loss, double learning_rate,int maxIt){
    eMatrix* tmp;
    double curr_loss;
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
  nn->train(inp,out,new eCrossEntropyLoss(),0.1,500);
  cout << nn->forward(inp) << endl;
}
