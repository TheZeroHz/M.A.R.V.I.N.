#include "ReactGenerator.h"
ReactGenerator engn;
int ReactWindow,ReactLogCount;
void setup() {
  Serial.begin(115200);
  engn.setWindowSize(4,7);
  ReactWindow=engn.getWindowSize();
  engn.character._personality_=_achiever_;
  engn.character._mood_=_positive_;
  engn.character._reaction_=_calm_;
  engn.setRewardMultiplier(1.45,5.5,2.9,8.5);

}

void loop() {
  if(Serial.available()>0){
    String x=Serial.readString();
    Reaction _react_=engn.getReaction(engn.character._personality_,engn.character._mood_,(Action)x.toInt());
    engn.addReactionLogs(_react_);
    double y=0;
    Serial.println("Input:"+(String)x.toInt());
    y=engn.getRewardLogsCount();
    engn.showRewardLogs();
    Serial.print("Reaction Logs: ");
    for(int i=0;i<engn.getReactionLogsCount();i++){
    Serial.print(engn.reactionName(engn.getReactionLog(i)));
    Serial.print(" ");
    }
    
    Serial.println();
    Serial.println("Probability Of Moods:");
    Serial.println(engn.character.positivity/(engn.character.positivity-engn.character.negativity));
    Serial.println(-engn.character.negativity/(engn.character.positivity-engn.character.negativity));
    Serial.print("Reaction Log Count:");
    Serial.println(y);
    Serial.print("Predicted Mood:");
    Serial.println(engn.moodName(engn.predictMood()));
    x=engn.reactionName(_react_);
    Serial.println("Output:"+x);
  }
  // put your main code here, to run repeatedly:

}
