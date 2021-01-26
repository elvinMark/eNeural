#include <eMath.hpp>
#include <iostream>
#include <vector>

using namespace std;

emath::eTensor::eTensor(){

}

emath::eTensor::eTensor(int num_mats,int rows, int cols){
  for(int i = 0;i<num_mats;i++)
    this->mats.push_back(new eMatrix(rows,cols));
}

void emath::eTensor::random(){
  for(int i = 0;i<this->mats.size();i++)
    this->mats[i]->random();
}

emath::eTensor* emath::eTensor::conv(emath::eTensor* T){
  eTensor* out = new eTensor();
  for(int i = 0;i<this->mats.size();i++)
    for(int j = 0;j<T->mats.size();j++)
      out->mats.push_back(this->mats[i]->conv(T->mats[i]));
  return out;
}

emath::eTensor* emath::eTensor::corr(emath::eTensor* T){
  eTensor* out = new eTensor();
  for(int i = 0;i<this->mats.size();i++)
    for(int j = 0;j<T->mats.size();j++)
      out->mats.push_back(this->mats[i]->corr(T->mats[i]));
  return out;
}


