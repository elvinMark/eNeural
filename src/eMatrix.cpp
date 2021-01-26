#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <eMath.hpp>

using namespace std;

emath::eMatrix::eMatrix(int rows,int cols){
  this->rows = rows;
  this->cols = cols;
  this->data = (double*)malloc(sizeof(double)*rows*cols);
}

void emath::eMatrix::zeros(){
  for(int i = 0;i < this->rows * this->cols;i++)
    this->data[i] = 0;
}

void emath::eMatrix::ones(){
  for(int i = 0;i < this->rows * this->cols;i++)
    this->data[i] = 1;
}
void emath::eMatrix::eye(){
  for(int i = 0;i<this->rows;i++){
    for(int j = 0;j<this->cols;j++){
      if(i==j)
	this->data[i*this->cols + j] = 1;
      else
	this->data[i*this->cols + j] = 0;
    }
  }
}

void emath::eMatrix::random(){
  for(int i = 0;i<this->rows * this->cols;i++)
    this->data[i] = rand()%1000 / 1000.0;
}

emath::eMatrix* emath::eMatrix::dot(emath::eMatrix* m1){
  int tmp,tmp1;
  emath::eMatrix* out;
  out = new emath::eMatrix(this->rows,m1->cols);
  double s;
  for(int i = 0;i<this->rows;i++){
    tmp = i*this->cols;
    tmp1 = i*m1->cols;
    for(int j = 0;j<m1->cols;j++){
      s = 0;
      for(int k = 0;k<this->cols;k++)
	s += this->data[tmp+k] * m1->data[k*m1->cols + j];
      out->data[tmp1 + j] = s;
    }
  }
  return out;
}

emath::eMatrix* emath::eMatrix::applyFunc(double fun_f(double)){
  emath::eMatrix* out;
  out = new emath::eMatrix(this->rows,this->cols);
  for(int i = 0;i<this->rows * this->cols;i++)
    out->data[i] = fun_f(this->data[i]);
  return out;
}

emath::eMatrix* emath::eMatrix::plus(emath::eMatrix* m1){
  emath::eMatrix* out;
  out = new eMatrix(this->rows,this->cols);
  if(this->rows == m1->rows && this->cols == m1->cols){
    for(int i = 0;i<this->rows * this->cols;i++)
      out->data[i] = this->data[i] + m1->data[i];
  }
  else if(this->rows == m1->rows && m1->cols == 1){
    for(int i = 0;i<this->rows * this->cols;i++)
      out->data[i] = this->data[i] + m1->data[i/this->cols];
  }
  else if(this->cols == m1->cols && m1->rows == 1){
     for(int i = 0;i<this->rows * this->cols;i++)
       out->data[i] = this->data[i] + m1->data[i%this->cols];
  }
  return out;
}

emath::eMatrix* emath::eMatrix::plus(double num ){
  emath::eMatrix* out;
  out = new eMatrix(this->rows,this->cols);
  for(int i = 0;i<this->rows * this->cols;i++)
    out->data[i] = this->data[i] + num;
  return out;
}

emath::eMatrix* emath::eMatrix::minus(emath::eMatrix* m1){
  emath::eMatrix* out;
  out = new eMatrix(this->rows,this->cols);
  for(int i = 0;i<this->rows * this->cols;i++)
    out->data[i] = this->data[i] - m1->data[i];
  return out;
}

emath::eMatrix* emath::eMatrix::minus(double num ){
  emath::eMatrix* out;
  out = new eMatrix(this->rows,this->cols);
  for(int i = 0;i<this->rows * this->cols;i++)
    out->data[i] = this->data[i] - num;
  return out;
}

emath::eMatrix* emath::eMatrix::times(emath::eMatrix* m1){
  emath::eMatrix* out;
  out = new eMatrix(this->rows,this->cols);
  if(this->rows == m1->rows && this->cols == m1->cols){
    for(int i = 0;i<this->rows * this->cols;i++)
      out->data[i] = this->data[i] * m1->data[i];
  }
  else if(this->rows == m1->rows && m1->cols == 1){
    for(int i = 0;i<this->rows * this->cols;i++)
      out->data[i] = this->data[i] * m1->data[i/this->cols];
  }
  else if(this->cols == m1->cols && m1->rows == 1){
    for(int i = 0;i<this->rows * this->cols;i++)
      out->data[i] = this->data[i] * m1->data[i%this->cols];
  }
  return out;
}

emath::eMatrix* emath::eMatrix::times(double num ){
  emath::eMatrix* out;
  out = new eMatrix(this->rows,this->cols);
  for(int i = 0;i<this->rows * this->cols;i++)
    out->data[i] = this->data[i] * num;
  return out;
}

emath::eMatrix* emath::eMatrix::divides(emath::eMatrix* m1){
  emath::eMatrix* out;
  out = new eMatrix(this->rows,this->cols);
  if(this->rows == m1->rows && this->cols == m1->cols){
    for(int i = 0;i<this->rows * this->cols;i++)
      out->data[i] = this->data[i] / m1->data[i];
  }
  else if(this->rows == m1->rows && m1->cols == 1){
    for(int i = 0;i<this->rows * this->cols;i++)
      out->data[i] = this->data[i] / m1->data[i/this->cols];
  }
  else if(this->cols == m1->cols && m1->rows == 1){
    for(int i = 0;i<this->rows * this->cols;i++)
      out->data[i] = this->data[i] / m1->data[i%this->cols];
  }
  return out;
}

emath::eMatrix* emath::eMatrix::divides(double num ){
  emath::eMatrix* out;
  out = new eMatrix(this->rows,this->cols);
  for(int i = 0;i<this->rows * this->cols;i++)
    out->data[i] = this->data[i] / num;
  return out;
}

double emath::eMatrix::sum(){
  double s = 0;
  for(int i = 0;i<this->rows * this->cols;i++)
    s += this->data[i];
  return s;
}

emath::eMatrix* emath::eMatrix::sum(int axis){
  emath::eMatrix* out;
  if(axis == 0){
    out = new emath::eMatrix(this->rows,1);
    out->zeros();
    for(int i = 0;i<this->rows * this->cols;i++)
      out->data[i/this->cols] += this->data[i];
  }
  else{
    out = new emath::eMatrix(1,this->cols);
    out->zeros();
    for(int i = 0;i<this->rows * this->cols;i++)
      out->data[i%this->cols] += this->data[i];
  }
  return out;
}

emath::eMatrix* emath::eMatrix::transpose(){
  emath::eMatrix* out;
  out = new emath::eMatrix(this->cols,this->rows);
  for(int i = 0;i<this->rows;i++)
    for(int j = 0;j<this->cols;j++)
      out->data[j*this->rows + i] = this->data[i*this->cols + j];
  return out;
}

emath::eMatrix* emath::eMatrix::conv(emath::eMatrix* m1){
  emath::eMatrix* out;
  out = new emath::eMatrix(this->rows - m1->rows + 1, this->cols - m1->cols + 1);
  for(int i = 0;i<out->rows;i++){
    for(int j = 0;j<out->cols;j++){
    }
  }
  return out;
}

emath::eMatrix* emath::eMatrix::corr(emath::eMatrix* m1){
  emath::eMatrix* out;
  out = new emath::eMatrix(this->rows + m1->rows - 1, this->cols + m1->cols - 1);
  for(int i = 0;i<out->rows;i++){
    for(int j = 0;j<out->cols;j++){
    }
  }
  return out;
}

ostream& operator<<(ostream& os,const emath::eMatrix* m){
  int tmp;
  for(int i = 0;i<m->rows;i++){
    tmp = i*m->cols;
    for(int j = 0;j<m->cols;j++)
      os << m->data[tmp + j] << " ";
    os << endl;
  }
  return os;
}

ostream& operator<<(ostream& os,const emath::eMatrix& m){
  int tmp;
  for(int i = 0;i<m.rows;i++){
    tmp = i*m.cols;
    for(int j = 0;j<m.cols;j++)
      os << m.data[tmp + j] << " ";
    os << endl;
  }
  return os;
}

emath::eMatrix operator + (const emath::eMatrix& m1, const emath::eMatrix& m2){
  emath::eMatrix out(m1.rows,m1.cols);
  for(int i = 0;i<m1.rows * m1.cols;i++)
    out.data[i] = m1.data[i] + m2.data[i];
  return out;
}

emath::eMatrix operator + (const emath::eMatrix& m1, const double num){
  emath::eMatrix out(m1.rows,m1.cols);
  for(int i = 0;i<m1.rows * m1.cols;i++)
    out.data[i] = m1.data[i] + num;
  return out;
}

emath::eMatrix operator - (const emath::eMatrix& m1, const emath::eMatrix& m2){
  emath::eMatrix out(m1.rows,m1.cols);
  for(int i = 0;i<m1.rows * m1.cols;i++)
    out.data[i] = m1.data[i] - m2.data[i];
  return out;
}

emath::eMatrix operator - (const emath::eMatrix& m1, const double num){
  emath::eMatrix out(m1.rows,m1.cols);
  for(int i = 0;i<m1.rows * m1.cols;i++)
    out.data[i] = m1.data[i] - num;
  return out;
}

emath::eMatrix operator * (const emath::eMatrix& m1, const emath::eMatrix& m2){
  emath::eMatrix out(m1.rows,m1.cols);
  for(int i = 0;i<m1.rows * m1.cols;i++)
    out.data[i] = m1.data[i] * m2.data[i];
  return out;
}

emath::eMatrix operator * (const emath::eMatrix& m1, const double num){
  emath::eMatrix out(m1.rows,m1.cols);
  for(int i = 0;i<m1.rows * m1.cols;i++)
    out.data[i] = m1.data[i] * num;
  return out;
}

emath::eMatrix operator / (const emath::eMatrix& m1, const emath::eMatrix& m2){
  emath::eMatrix out(m1.rows,m1.cols);
  for(int i = 0;i<m1.rows * m1.cols;i++)
    out.data[i] = m1.data[i] / m2.data[i];
  return out;
}

emath::eMatrix operator / (const emath::eMatrix& m1, const double num){
  emath::eMatrix out(m1.rows,m1.cols);
  for(int i = 0;i<m1.rows * m1.cols;i++)
    out.data[i] = m1.data[i] / num;
  return out;
}
