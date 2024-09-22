#include "ReactGenerator.h"
ReactGenerator engn;
Personality _personality_;
Mood _mood_;
void setup() {
  Serial.begin(115200);

  engn.setFrameSize(6);
  engn.setWindowSize(3);

  engn.character._personality_=_balanced_;
  _personality_=engn.character._personality_;

  engn.character._mood_=_neutral_;
  _mood_=  engn.character._mood_;
  engn.addMoodLogs(engn.character._mood_);
  engn.moodChangeCounter=1;
/////////// PADDING VALUES //////////////
      engn.addRewardLogs(0);
      engn.addRewardLogs(0);
      engn.addReactionLogs(_calm_);
      engn.addReactionLogs(_calm_);
///////////////////////////////////////

  engn.setRewardMultiplier(1.45,5.5,2.9,8.5);
}
int counter=0;
String reaction,mood,personality;
void loop() {
  if(Serial.available()>0){
    counter++;
    String input=Serial.readString();

    Action _action_=(Action)input.toInt();
    Serial.println("Input:"+(String)engn.getActionName(_action_));
    Reaction _react_=engn.getReaction(engn.character._personality_,engn.character._mood_,_action_);
    engn.addReactionLogs(_react_);
    engn.slideWindow(engn.reward_logs,engn.getFrameSize(),engn.getWindowSize());
    if(engn.character.moodChanged){_mood_=engn.predictMood();engn.addMoodLogs(_mood_);}
    if(engn.moodChangeCounter==engn.getFrameSize())_personality_=engn.predictPersonality();
    engn.character._mood_=_mood_;
    engn.character._reaction_=_react_;
    engn.character._personality_=_personality_;
    engn.showRewardLogs();
    //engn.showReactionLogs();
    engn.showMoodLogs();
    engn.showMoodDetails();
    engn.CMD.nl();
    
    reaction=engn.reactionName(_react_);
    mood=engn.moodName(_mood_);
    personality=engn.personalityName(_personality_);

    Serial.println("Reaction :"+reaction+"\nMood :"+mood+"\nPersonality :"+personality);
    Serial.println();
  }
  // put your main code here, to run repeatedly:

}
