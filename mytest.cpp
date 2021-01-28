#include <iostream>
#include <math.h>
#include <eMath.hpp>
#include <eNeural.hpp>
#include <vector>

using namespace std;
using namespace emath;
using namespace enn;

int  main(){
  double in_data[8] = {0,0,0,1,1,0,1,1};
  double out_data[8] = {1,0,0,1,0,1,1,0};
  eMatrix* inp,*out;
  eMLPClassifier* nn = new eMLPClassifier({2,5,3,2},enn::RELU);
  inp = new eMatrix(4,2);
  out = new eMatrix(4,2);
  
  inp->data = in_data;
  out->data = out_data;
  
  cout << nn->forward(inp) << endl;
  //nn->train(inp,out,0.1,500);
  nn->load_model("test.bin");
  cout << nn->forward(inp) << endl;

  //nn->save_model("test.bin");
  
}
