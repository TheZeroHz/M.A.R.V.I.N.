#include"CLI.h"

void CLI::showDoubleVec(Vector<double> &vec){
  for(int i=0;i<vec.size();i++){
     Serial.print(vec[i]);
     Serial.print(" ");
    }
}

template<typename T>
void CLI::show(const T& value){
  Serial.print(value);
}

void CLI::nl(){
  Serial.println();
}