#include "ReactGenerator.h"
void setup() {
  Serial.begin(115200);
   ReactGenerator engine;
   CharacterState character;
    character._personality_ = _balanced_;
    character._mood_ = _positive_;
    character._reaction_ = _happy_;
    character._mfactor_ = 0; // Initial mood factor
    character._pfactor_ = 0; // Initial personality factor

}

void loop() {
  if(Serial.available()>0){
    String x=Serial.readString();
    Serial.println("Input:"+x);
  }
  // put your main code here, to run repeatedly:

}
