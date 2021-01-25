#include <iostream>
#include "eMath.hpp"

#ifndef E_NEURAL
#define E_NEURAL

using namespace std;
using namespace emath;

namespace enn{
  class eLinear;
  class eSigmoid;
  class eTanh;
  class eReLU;
  class eSoftmax;
  class eMeanSquareLoss;
  class eCrossEntropyLoss;
}

class enn::eLinear{
public:
  eMatrix *W;
  eMatrix *b;
  eMatrix *tmp_in;
  eMatrix *tmp_out;
  eMatrix *tmp_err;
  
  eLinear(int num_inputs,int num_outputs);
  eMatrix* forward(eMatrix* inp);
  eMatrix* backward(eMatrix* err);
  void     update(double learing_rate);
};

class enn::eSigmoid{
public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
};

class enn::eTanh{
  public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
};

class enn::eReLU{
public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
};

class enn::eSoftmax{
public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
};

class enn::eMeanSquareLoss{
public:
  eMatrix* tmp_err;
  double loss(eMatrix* out, eMatrix* target);
  eMatrix* grad_loss();
};

class enn::eCrossEntropyLoss{
public:
  eMatrix* tmp_err;
  double loss(eMatrix* out, eMatrix* target);
  eMatrix* grad_loss();
};

ostream& operator << (ostream& os,const enn::eLinear& nn);
ostream& operator << (ostream& os,const enn::eLinear* nn);
#endif
