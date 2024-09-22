#include"smaPersonality.h"

void SMA::setFrameSize(int SIZE_OF_FRAME){
  frame_size=SIZE_OF_FRAME;
}

int SMA::getFrameSize(){
  return frame_size;
}


void SMA::rescale( float& posSMA, float& negSMA, float& neuSMA){
  if(posSMA>0.333333)posSMA=1;
  else posSMA=0;
  if(negSMA>0.333333)negSMA=1;
  else negSMA=0;
  if(neuSMA>0.333333)neuSMA=1;
  else neuSMA=0;  
}


void SMA::calculateSMA(Vector<Mood>& moodLogs, float& posSMA, float& negSMA, float& neuSMA){
    int posCount = 0, negCount = 0, neuCount = 0;
    int count = min(frame_size, (int)moodLogs.size());
    for (int i = moodLogs.size() - count; i < moodLogs.size(); ++i) {
        if (moodLogs[i] == _positive_) {
            posCount++;
        } else if (moodLogs[i] == _negative_) {
            negCount++;
        } else if (moodLogs[i]== _neutral_) {
            neuCount++;
        }
    }

    posSMA = (float)posCount / count;
    negSMA = (float)negCount / count;
    neuSMA = (float)neuCount / count;
}

Personality SMA::predictPersonality(Vector<Mood> moodLogs){
  float posSMA, negSMA, neuSMA;
  calculateSMA(moodLogs, posSMA, negSMA, neuSMA);
  if(debug)
  Serial.printf("Before scaling posSMA:%f neuSMA:%f negSMA:%f \n",posSMA,neuSMA,negSMA);
  rescale(posSMA, negSMA, neuSMA);
  if(debug)
  Serial.printf("After sacling posSMA:%f neuSMA:%f negSMA:%f \n",posSMA,neuSMA,negSMA);
  bool p=(bool)posSMA;
  bool n=(bool)negSMA;
  bool m=(bool)neuSMA;
  if(debug){
  Serial.println(p);
  Serial.println(m);
  Serial.println(n);
  }
  if((!p&!m&!n)||(p&m&n)||(p&!m&n)||(!p&m&!n))return _balanced_;//  [111][000][101][010]
  else if(p&m&!n)return _creative_;//[110]
  else if(p&!m&!n)return _achiever_;//[100]
  else if((!p&!m&n)||(!p&m&n)) return _distressed_; //[001][011]
  else return _balanced_;
}