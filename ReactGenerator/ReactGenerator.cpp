#include "ReactGenerator.h"
// Function to get Reaction based on personality, mood, and action
Reaction ReactGenerator::getReaction(Personality p, Mood m, Action a) {
    return tiny_DB[p][m][a];
}

void ReactGenerator::setReaction(Personality p, Mood m, Action a, Reaction e) {
    tiny_DB[p][m][a] = e;
}

void ReactGenerator::adjustReinforcement(Action a){
  count_RL_loop++;
    if(character._mfactor_>1)character._mfactor_=1;
  else if(character._mfactor_<-1)character._mfactor_=-1;
  character._reaction_=getReaction(character._personality_,character._mood_,a);
  switch(a){
    case _hithead_:moodchangefactor=-0.30;break;
    case _hitback_:moodchangefactor=-0.20;break;
    case _hitbelly_:moodchangefactor=-0.15;break;
    case _hithand_:moodchangefactor=-0.10;break;
    case _handmassage_:moodchangefactor=0.10;break;
    case _bellymassage_:moodchangefactor=0.15;break;
    case _backmassage_:moodchangefactor=0.20;break;
    case _headmassage_:moodchangefactor=0.30;break;
    case _fall_:moodchangefactor=-0.20;break;
    case _shake_:moodchangefactor=-0.15;break;
    case _hang_:moodchangefactor=-0.25;break;
    case _idle_:
    switch(character._mood_){
      case _positive_:moodchangefactor=-0.015;break;
      case _neutral_:moodchangefactor=0.015;break;
      case _negative_:moodchangefactor=0.025;break;
      default: break;
    }
    case _call_:
    switch(character._mood_){
      case _positive_:moodchangefactor=0.015;break;
      case _neutral_:moodchangefactor=0;break;
      case _negative_:moodchangefactor=0.025;break;
      default: break;
    }
    case _recognized_:
      switch(character._mood_){
      case _positive_:moodchangefactor=0.015;break;
      case _neutral_:moodchangefactor=0;break;
      case _negative_:moodchangefactor=0.025;break;
      default: break;
    }

  }

  if(moodchangefactor<0)character._nchanges_=moodchangefactor+character._nchanges_;
  else character._pchanges_=moodchangefactor+character._pchanges_;
  character._mfactor_=character._mfactor_+moodchangefactor*changeSPEED;
switch(character._reaction_) {
    // penalties
    case _superanger_:
    switch(character._personality_){ 
      case _achiever_:moodchangefactor=-0.1*changeSPEED;break;
      case _balanced_:moodchangefactor=-0.09*changeSPEED;break;
      case _creative_:moodchangefactor=-0.08*changeSPEED;break;
      case _distressed_:moodchangefactor=-0.07*changeSPEED;break;
    }
    break;
    case _anger_:
        switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _supersad_:  switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _sad_:   switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _annoyed_:   switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _scared_:   switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _frustrated_:   switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _confused_:   switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    // rewards
    case _shy_:   switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _curious_:   switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _excited_:   switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _surprised_:   switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _playful_:   switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _affectionate_:   switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _happy_:  switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    case _superhappy_:  switch(character._personality_){ 
      case _achiever_:moodchangefactor= 0.1 *changeSPEED;break;
      case _balanced_:moodchangefactor= 0.1 *changeSPEED;break;
      case _creative_:moodchangefactor=-0.1 *changeSPEED;break;
      case _distressed_:moodchangefactor=0.1 *changeSPEED;break;
    }
    break;
    default: break;
}
  if(moodchangefactor<0)character._nchanges_=moodchangefactor+character._nchanges_;
  else character._pchanges_=moodchangefactor+character._pchanges_;

character._mfactor_=character._mfactor_+moodchangefactor;
if(count_RL_loop>10){
  if(abs(character._nchanges_)>abs(character._pchanges_))character._mood_=character._mood_-1;
  else character._mood_=character._mood_+1;
  if(character._mood_<0)character._mood_=_positive_;
  else(character._mood_>2)character._mood_=_negative_;
  character._nchanges_=0;
  character._pchanges_=0;
  character._mfactor_=0;
  moodchangefactor=0;
  count_RL_loop=0;

  }

        
}

char *ReactGenerator::reactionName(Reaction E) {
    switch (E) {
        case _anger_: return "anger";
        case _superanger_: return "superanger";
        case _annoyed_: return "angry";
        case _sad_: return "sad";
        case _scared_: return "scared";
        case _confused_: return "confused";
        case _calm_: return "calm";
        case _curious_: return "curious";
        case _excited_: return "excited";
        case _surprised_: return "surprised";
        case _affectionate_: return "affectionate";
        case _frustrated_: return "frustrated";
        case _supersad_: return "supersad";
        case _shy_: return "shy";
        case _happy_: return "happy";
        case _playful_: return "playful";
        case _superhappy_: return "superhappy";
        default: return "nothing"; // Return "unknown" if the Reaction is not recognized
    }
}
// Constructor to initialize tiny_DB array
ReactGenerator::ReactGenerator() {
  character._personality_=_balanced_;
  character._mood_=_positive_;
  character._mfactor_=0;
  character._pfactor_=0;

// Initialize for achiever here
        tiny_DB[_achiever_][_positive_][_hithead_] = _annoyed_;
        tiny_DB[_achiever_][_positive_][_hitbelly_] = _annoyed_;
        tiny_DB[_achiever_][_positive_][_hithand_] = _annoyed_;
        tiny_DB[_achiever_][_positive_][_hitback_] = _annoyed_;
        tiny_DB[_achiever_][_neutral_][_hithead_] = _anger_;
        tiny_DB[_achiever_][_neutral_][_hitbelly_] = _anger_;
        tiny_DB[_achiever_][_neutral_][_hithand_] = _anger_;
        tiny_DB[_achiever_][_neutral_][_hitback_] = _anger_;
        tiny_DB[_achiever_][_negative_][_hithead_] = _superanger_;
        tiny_DB[_achiever_][_negative_][_hitbelly_] = _superanger_;
        tiny_DB[_achiever_][_negative_][_hithand_] = _superanger_;
        tiny_DB[_achiever_][_negative_][_hitback_] = _superanger_;
        // Initialize for _balanced_ here
		tiny_DB[_balanced_][_positive_][_hithead_] = _confused_;
		tiny_DB[_balanced_][_positive_][_hitbelly_] = _confused_;
		tiny_DB[_balanced_][_positive_][_hithand_] = _confused_;
		tiny_DB[_balanced_][_positive_][_hitback_] = _confused_;

		tiny_DB[_balanced_][_neutral_][_hithead_] = _calm_;
		tiny_DB[_balanced_][_neutral_][_hitbelly_] = _calm_;
		tiny_DB[_balanced_][_neutral_][_hithand_] = _calm_;
		tiny_DB[_balanced_][_neutral_][_hitback_] = _calm_;

		tiny_DB[_balanced_][_negative_][_hithead_] = _sad_;
		tiny_DB[_balanced_][_negative_][_hitbelly_] = _anger_;
		tiny_DB[_balanced_][_negative_][_hithand_] = _annoyed_;
		tiny_DB[_balanced_][_negative_][_hitback_] = _anger_;

}
