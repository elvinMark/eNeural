#include <iostream>
#include "eMath.hpp"

#ifndef E_NEURAL
#define E_NEURAL

using namespace std;
using namespace emath;

namespace enn{
  class eLayer;
  class eLinear;
  class eSigmoid;
  class eTanh;
  class eReLU;
  class eSoftmax;

  class eLoss;
  class eMeanSquareLoss;
  class eCrossEntropyLoss;
}

class enn::eLayer{
public:
  virtual  eMatrix* forward(eMatrix* inp) = 0;
  virtual  eMatrix* backward(eMatrix* err) = 0;
  virtual  void     update(double learing_rate) = 0;
};

class enn::eLinear : public enn::eLayer{
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

class enn::eSigmoid : public enn::eLayer{
public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
};

class enn::eTanh : public enn::eLayer{
  public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
};

class enn::eReLU : public enn::eLayer{
public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
};

class enn::eSoftmax : public enn::eLayer{
public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
};

class enn::eLoss{
public:
  virtual double loss(eMatrix* out, eMatrix* target) = 0;
  virtual eMatrix* grad_loss() = 0;
};

class enn::eMeanSquareLoss : public enn::eLoss{
public:
  eMatrix* tmp_err;
  double loss(eMatrix* out, eMatrix* target);
  eMatrix* grad_loss();
};

class enn::eCrossEntropyLoss : public enn::eLoss{
public:
  eMatrix* tmp_err;
  double loss(eMatrix* out, eMatrix* target);
  eMatrix* grad_loss();
};

ostream& operator << (ostream& os,const enn::eLinear& nn);
ostream& operator << (ostream& os,const enn::eLinear* nn);
#endif
