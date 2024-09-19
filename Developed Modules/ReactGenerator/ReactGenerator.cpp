#include "ReactGenerator.h"


//.|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||.
//. ============================= Initializers ================================== .
//.|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||.

//######### Constructor #########//
ReactGenerator::ReactGenerator() {
  rwdDB.load(_FLASH_); //load rewards and penalty scores(_FLASH_=>sketch,_SPIFF_=>spiff,_APP_=>android app,_CLOUD_=>download)
  rctDB.load(_FLASH_); //load reaction datapoints (_FLASH_=>sketch,_SPIFF_=>spiff,_APP_=>android app,_CLOUD_=>download)
  character._personality_ = _balanced_;
  character._mood_ = _positive_;
  character._reaction_ = _calm_;
}

void ReactGenerator::setFrameSize(int _size_){
  _FrameSize_=_size_;
}
int ReactGenerator::getFrameSize(){
  return _FrameSize_;
}

//###### How many cotigious log should be considered for upDate mood ####//
void ReactGenerator::setWindowSize(int _size_){
  _WindowSize_=_size_;
}
//### get the size of window ###//
int ReactGenerator::getWindowSize(){
  return _WindowSize_;
}

/* Reduces the _Reward_ effect for same reaction multiple times.
Ex: reactionLog->{sad sad sad sad}.rewardLog->{-0.5,-0.45,-0.38,-0.33} */
void ReactGenerator::setRewardMultiplier(double achiever, double balanced, double creative, double distressed){
  reward_Multiplier[_achiever_]=achiever;reward_Multiplier[_balanced_]=balanced;
  reward_Multiplier[_creative_]=creative;reward_Multiplier[_distressed_]=distressed;
}




//////////////// Reaction Manipulation ///////////////
void ReactGenerator::setReaction(Personality p, Mood m, Action a, Reaction e) {
  rctDB.react_DB[p][m][a] = e;
}
Reaction ReactGenerator::getReaction(Personality p, Mood m, Action a) {
  addRewardLogs(rwdDB.reward_DB[p].val[rctDB.react_DB[p][m][a]]);
  return rctDB.react_DB[p][m][a];
}
char *ReactGenerator::reactionName(Reaction R) {
  return rctDB.datapoint_Name(R);
}


//.|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||.
//. ============================ Slider Karnel ================================== .
//.|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||.

void ReactGenerator::slideWindow(Vector<double> &arr, int _frameSize_, int _windowSize_) {
  if(arr.size()==_windowSize_){
    character.moodChanged=true;
  }
  if (arr.size() >= _windowSize_) {
    character.moodChanged=true;
    if (arr.size() > _frameSize_) arr.popFront(1);
    Serial.print("Window:");
    character.MoodNegativity=0;
    character.MoodPositivity=0;
    for (int i = arr.size() - _windowSize_; i < arr.size(); i++) {
      if (arr[i]>= 0) character.MoodPositivity += arr[i];
      else character.MoodNegativity += arr[i];
      Serial.print(arr[i]);
      Serial.print(" ");
    }
    CMD.nl();
    Serial.print("Frame:");
    for (int i = 0; i < arr.size(); i++) {
      Serial.print(arr[i]);
      Serial.print(" ");
    }
    CMD.nl();
  }
  else{
    character.moodChanged=false;
  }
}



//.|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||.
//. ============================= Reaction Log ================================== .
//.|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||.
void ReactGenerator::addReactionLogs(Reaction R){
  reaction_logs.push_back(R);
  if(reaction_logs.size()>_WindowSize_)reaction_logs.popFront(_WindowSize_);
}
Reaction ReactGenerator::getReactionLog(int index){
  return reaction_logs[index];
}
int ReactGenerator::getReactionLogsCount(){
  return reaction_logs.size();
}

void ReactGenerator::showReactionLogs(){
    Serial.print("Reaction Logs: ");
    for(int i=0;i<getReactionLogsCount();i++){
    Serial.print(reactionName(getReactionLog(i)));
    Serial.print(" ");
    }
    CMD.nl();
}










//.|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||.
//. ============================= Reward  Logs ================================== .
//.|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||.

//## Add every rewards from generated reaction to logs ##//
void ReactGenerator::addRewardLogs(double x) {
  reward_logs.push_back(x);
}
//## Get the rewards by index from logs ##//
double ReactGenerator::getRewardLog(int index) {
  return reward_logs[index];
}
Vector<double> ReactGenerator::getRewardLog(){
  return reward_logs;
}
void ReactGenerator::showRewardLogs(){
  Serial.print("Reward Logs: ");
  CMD.showDoubleVec(reward_logs);
  CMD.nl();
}

//## Count How Many logs Have been added ##//
int ReactGenerator::getRewardLogsCount() {
  return reward_logs.size();
}




char *ReactGenerator::moodName(Mood M) {
  switch (M) {
    case _positive_: return "Positive";
    case _negative_: return "Negative";
    case _neutral_: return "Neutral";
    default: return "Unknown Mood";
  }
}

void ReactGenerator::showMoodDetails(){
  float positivity=(character.MoodPositivity / (character.MoodPositivity  - character.MoodNegativity))*100.0;
  float negativity=(-character.MoodNegativity / (character.MoodPositivity  - character.MoodNegativity))*100.0;
    Serial.print("positivity:");Serial.print(positivity);Serial.print("%");
    Serial.print(" ");
    Serial.print("negativity:");Serial.print(negativity);Serial.print("%");

}
Mood ReactGenerator::predictMood() {
  if(getReactionLogsCount()>=getWindowSize()){
  double pos = character.MoodPositivity / (character.MoodPositivity  - character.MoodNegativity);
  double neg = -character.MoodNegativity / (character.MoodPositivity  - character.MoodNegativity);
  if (pos - neg > random(0.15, 0.25)) {
    character._mood_ = _positive_;
    return _positive_;
  } else if (pos - neg < 0) {
    character._mood_ = _negative_;
    return _negative_;
  } else if (pos - neg >= 0 && pos - neg <= 0.25) {
    character._mood_ = _neutral_;
    return _neutral_;
  }
  }
  else return character._mood_;
}



