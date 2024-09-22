/// SMA Stands For Simple Moving Avarage /////
#ifndef SMAPERSONALITY_h
#define SMAPERSONALITY_h
#include <Arduino.h>
#include "RG_config.h"
#include "Vector.h"
#include <numeric>
#include <algorithm>
using namespace std;

class SMA{
  private:
  bool debug=false;
  int frame_size;
  void rescale( float& posSMA, float& negSMA, float& neuSMA);
  void calculateSMA(Vector<Mood>& moodLogs, float& posSMA, float& negSMA, float& neuSMA);
  public:
  void setFrameSize(int SIZE_OF_FRAME);
  int getFrameSize();
  Personality predictPersonality(Vector<Mood> moodLogs);
};
#endif