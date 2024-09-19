#include "ReactGenerator.h"
ReactGenerator engn;
void setup() {
  Serial.begin(115200);
  engn.setFrameSize(20);
  engn.setWindowSize(4);
  engn.character._personality_=_achiever_;
  engn.character._mood_=_positive_;
  engn.character._reaction_=_calm_;
  engn.setRewardMultiplier(1.45,5.5,2.9,8.5);
}

void loop() {
  if(Serial.available()>0){
    String x=Serial.readString();
    Serial.println("Input:"+(String)x.toInt());
    Reaction _react_=engn.getReaction(engn.character._personality_,engn.character._mood_,(Action)x.toInt());
    engn.addReactionLogs(_react_);
    engn.slideWindow(engn.reward_logs,engn.getFrameSize(),engn.getWindowSize());
    engn.showRewardLogs();
    engn.showReactionLogs();
    engn.showMoodDetails();
    engn.CMD.nl();
    Serial.print("Predicted Mood:");
    Serial.println(engn.moodName(engn.predictMood()));
    x=engn.reactionName(_react_);
    Serial.println("Output:"+x);
  }
  // put your main code here, to run repeatedly:

}
