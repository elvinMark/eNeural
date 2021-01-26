#include <iostream>
#include <vector>

#ifndef E_MATH
#define E_MATH

using namespace std;

namespace emath{
  class eMatrix;
  class eTensor;
}

class emath::eMatrix{
public:
  double* data;
  int rows, cols;
  eMatrix(int rows,int cols);
  void zeros();
  void ones();
  void eye();
  void random();
  emath::eMatrix* plus(emath::eMatrix* m1);
  emath::eMatrix* plus(double num);
  emath::eMatrix* minus(emath::eMatrix* m1);
  emath::eMatrix* minus(double num);
  emath::eMatrix* times(emath::eMatrix* m1);
  emath::eMatrix* times(double num);
  emath::eMatrix* divides(emath::eMatrix* m1);
  emath::eMatrix* divides(double num);
  double          sum();
  emath::eMatrix* sum(int axis);
  emath::eMatrix* transpose();
  emath::eMatrix* dot(emath::eMatrix* m1);
  emath::eMatrix* applyFunc(double fun_f(double));
  emath::eMatrix* conv(emath::eMatrix* m1);
  emath::eMatrix* corr(emath::eMatrix* m1);
};
ostream& operator << (ostream& os,const emath::eMatrix* m);
ostream& operator << (ostream& os,const emath::eMatrix& m);
emath::eMatrix operator + (const emath::eMatrix& m1, const emath::eMatrix& m2);
emath::eMatrix operator + (const emath::eMatrix& m1, const double num);
emath::eMatrix operator - (const emath::eMatrix& m1, const emath::eMatrix& m2);
emath::eMatrix operator - (const emath::eMatrix& m1, const double num);
emath::eMatrix operator * (const emath::eMatrix& m1, const emath::eMatrix& m2);
emath::eMatrix operator * (const emath::eMatrix& m1, const double num);
emath::eMatrix operator / (const emath::eMatrix& m1, const emath::eMatrix& m2);
emath::eMatrix operator / (const emath::eMatrix& m1, const double num);

class emath::eTensor{
public:
  std::vector<eMatrix*> mats;
  eTensor(int num_mats,int rows, int cols);
  emath::eTensor* conv(emath::eTensor* T);
}
#endif
