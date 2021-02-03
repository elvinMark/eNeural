#include <iostream>
#include "eMath.hpp"
#include <vector>

#ifndef E_NEURAL
#define E_NEURAL

using namespace std;
using namespace emath;

namespace enn{
  const int   SIGMOID = 0;
  const int   TANH = 1;
  const int   RELU = 2;
  class eLayer;
  class eLinear;
  class eSigmoid;
  class eTanh;
  class eReLU;
  class eSoftmax;
  class eDropout;
  
  class eLoss;
  class eMeanSquareLoss;
  class eCrossEntropyLoss;

  class eModel;
  class eSequential;
  class eMLPClassifier;
}

class enn::eLayer{
public:
  virtual  eMatrix* forward(eMatrix* inp) = 0;
  virtual  eMatrix* backward(eMatrix* err) = 0;
  virtual  void     update(double learing_rate) = 0;
  virtual  void     load(FILE* p) = 0;
  virtual  void     save(FILE* p) = 0;
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
  void     load(FILE* p);
  void     save(FILE* p);
};

class enn::eSigmoid : public enn::eLayer{
public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
  void     load(FILE* p);
  void     save(FILE* p);
};

class enn::eTanh : public enn::eLayer{
public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
  void     load(FILE* p);
  void     save(FILE* p);
};

class enn::eReLU : public enn::eLayer{
public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
  void     load(FILE* p);
  void     save(FILE* p);
};

class enn::eSoftmax : public enn::eLayer{
public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
  void     load(FILE* p);
  void     save(FILE* p);
};

class enn::eDropout : public enn::eLayer{
public:
  eMatrix* tmp_in;
  eMatrix* tmp_out;
  eMatrix* tmp_err;
  eMatrix* mask;
  double   p;
  double   alpha;
  double   (*criteria)(double);
  
  eDropout(double p);
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
  void     load(FILE* p);
  void     save(FILE* p);
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

class enn::eModel{
public:
  virtual eMatrix* forward(eMatrix *inp) = 0;
  virtual eMatrix* backward(eMatrix *err) = 0;
  virtual void     update(double learning_rate) = 0;
  virtual void     train(eMatrix* inp,eMatrix *out, eLoss *loss, double learning_rate, int maxIt) = 0;
  virtual void     load_model(const char* dir) = 0;
  virtual void     save_model(const char* dir) = 0;
};

class enn::eSequential : public enn::eModel{
public:
  std::vector<enn::eLayer *> layers;
  void     add(enn::eLayer* layer);
  eMatrix* forward(eMatrix *inp);
  eMatrix* backward(eMatrix *err);
  void     update(double learning_rate);
  void     train(eMatrix* inp,eMatrix *out, eLoss *loss, double learning_rate, int maxIt);
  void     load_model(const char* dir);
  void     save_model(const char* dir);
};

class enn::eMLPClassifier : public enn::eSequential{
public:
  eMLPClassifier(std::vector<int> structure,int act_fun);
  void     train(eMatrix* inp,eMatrix *out, double learning_rate, int maxIt);
};

ostream& operator << (ostream& os,const enn::eLinear& nn);
ostream& operator << (ostream& os,const enn::eLinear* nn);
#endif
