#include <iostream>
#include <math.h>
#include <eMath.hpp>
#include <eNeural.hpp>
#include <eData.h>
#include <vector>

using namespace std;
using namespace emath;
using namespace enn;

int  main(){
  double in_data[8] = {0,0,0,1,1,0,1,1};
  double out_data[8] = {1,0,0,1,0,1,1,0};
  eMatrix** data;
  eMLPClassifier* nn = new eMLPClassifier({2,5,3,2},enn::RELU);

  data = generate_data(20);
  
  cout << data[1] << endl;

  nn->train(data[0],data[1],0.1,1000);
  //nn->load_model("test.bin");
  cout << nn->forward(data[0]) << endl;

  //nn->save_model("test.bin");
  
}
