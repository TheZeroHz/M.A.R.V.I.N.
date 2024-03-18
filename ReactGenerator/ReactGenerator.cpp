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

//###### How many cotigious log should be considered for upDate mood ####//
void ReactGenerator::setWindowSize(int _Min_, int _Max_){
  _WindowSize_=random(_Min_,_Max_+1);
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
//. ============================= Reaction Log ================================== .
//.|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||.
void ReactGenerator::addReactionLogs(Reaction R){
  reaction_logs.push_back(R);
}
Reaction ReactGenerator::getReactionLog(int index){
  return reaction_logs[index];
}
int ReactGenerator::getReactionLogsCount(){
  return reaction_logs.size();
}












//.|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||.
//. ============================= Reward  Logs ================================== .
//.|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||.

//## Add every rewards from generated reaction to logs ##//
void ReactGenerator::addRewardLogs(double x) {
  if (x >= 0) character.positivity += x;
  else character.negativity += x;
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

Mood ReactGenerator::predictMood() {
  if(getReactionLogsCount()>=getWindowSize()){
  double pos = character.positivity / (character.positivity - character.negativity);
  double neg = -character.negativity / (character.positivity - character.negativity);
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



