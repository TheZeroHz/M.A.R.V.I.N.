#include"reactDB.h"
char * reactDB::datapoint_Name(Reaction r){
    switch (r) {
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
    default: return "Unknown Reaction";  // Return "unknown" if the Reaction is not initialized in RG_config
  }
}
void reactDB::load(LoadFrom loader){
////////////////////////////  Hit Head  /////////////////////////////
  react_DB[_achiever_][_positive_][_hithead_] = _annoyed_;
  react_DB[_achiever_][_neutral_][_hithead_] = _anger_;
  react_DB[_achiever_][_negative_][_hithead_] = _superanger_;

  react_DB[_balanced_][_positive_][_hithead_] = _confused_;
  react_DB[_balanced_][_neutral_][_hithead_] = _sad_;
  react_DB[_balanced_][_negative_][_hithead_] = _annoyed_;

  react_DB[_creative_][_positive_][_hithead_] = _scared_;
  react_DB[_creative_][_neutral_][_hithead_] = _sad_;
  react_DB[_creative_][_negative_][_hithead_] = _anger_;

  react_DB[_distressed_][_positive_][_hithead_] = _sad_;
  react_DB[_distressed_][_neutral_][_hithead_] = _supersad_;
  react_DB[_distressed_][_negative_][_hithead_] = _frustrated_;



  ////////////////////////////  Hit Belly  ////////////////////////////
  react_DB[_achiever_][_positive_][_hitbelly_] = _anger_;
  react_DB[_achiever_][_neutral_][_hitbelly_] = _frustrated_;
  react_DB[_achiever_][_negative_][_hitbelly_] = _superanger_;

  react_DB[_balanced_][_positive_][_hitbelly_] = _confused_;
  react_DB[_balanced_][_neutral_][_hitbelly_] = _annoyed_;
  react_DB[_balanced_][_negative_][_hitbelly_] = _anger_;

  react_DB[_creative_][_positive_][_hitbelly_] = _annoyed_;
  react_DB[_creative_][_neutral_][_hitbelly_] = _annoyed_;
  react_DB[_creative_][_negative_][_hitbelly_] = _anger_;

  react_DB[_distressed_][_positive_][_hitbelly_] = _confused_;
  react_DB[_distressed_][_neutral_][_hitbelly_] = _sad_;
  react_DB[_distressed_][_negative_][_hitbelly_] = _supersad_;



  /////////////////////////////   Hit Hand   ////////////////////////
  react_DB[_achiever_][_positive_][_hithand_] = _annoyed_;
  react_DB[_achiever_][_neutral_][_hithand_] = _anger_;
  react_DB[_achiever_][_negative_][_hithand_] = _frustrated_;

  react_DB[_balanced_][_positive_][_hithand_] = _confused_;
  react_DB[_balanced_][_neutral_][_hithand_] = _annoyed_;
  react_DB[_balanced_][_negative_][_hithand_] = _anger_;

  react_DB[_creative_][_positive_][_hithand_] = _confused_;
  react_DB[_creative_][_neutral_][_hithand_] = _annoyed_;
  react_DB[_creative_][_negative_][_hithand_] = _annoyed_;

  react_DB[_distressed_][_positive_][_hithand_] = _confused_;
  react_DB[_distressed_][_neutral_][_hithand_] = _sad_;
  react_DB[_distressed_][_negative_][_hithand_] = _supersad_;



  /////////////////////////////   Hit Back   ////////////////////////
  react_DB[_achiever_][_positive_][_hitback_] = _annoyed_;
  react_DB[_achiever_][_neutral_][_hitback_] = _anger_;
  react_DB[_achiever_][_negative_][_hitback_] = _superanger_;

  react_DB[_balanced_][_positive_][_hitback_] = _confused_;
  react_DB[_balanced_][_neutral_][_hitback_] = _annoyed_;
  react_DB[_balanced_][_negative_][_hitback_] = _anger_;

  react_DB[_creative_][_positive_][_hitback_] = _confused_;
  react_DB[_creative_][_neutral_][_hitback_] = _annoyed_;
  react_DB[_creative_][_negative_][_hitback_] = _annoyed_;

  react_DB[_distressed_][_positive_][_hitback_] = _frustrated_;
  react_DB[_distressed_][_neutral_][_hitback_] = _sad_;
  react_DB[_distressed_][_negative_][_hitback_] = _supersad_;



  /////////////////////// Fall /////////////////////////
  react_DB[_achiever_][_positive_][_fall_] = _scared_;
  react_DB[_achiever_][_neutral_][_fall_] = _scared_;
  react_DB[_achiever_][_negative_][_fall_] = _scared_;

  react_DB[_balanced_][_positive_][_fall_] = _scared_;
  react_DB[_balanced_][_neutral_][_fall_] = _scared_;
  react_DB[_balanced_][_negative_][_fall_] = _scared_;

  react_DB[_creative_][_positive_][_fall_] = _scared_;
  react_DB[_creative_][_neutral_][_fall_] = _scared_;
  react_DB[_creative_][_negative_][_fall_] = _scared_;

  react_DB[_distressed_][_positive_][_fall_] = _scared_;
  react_DB[_distressed_][_neutral_][_fall_] = _scared_;
  react_DB[_distressed_][_negative_][_fall_] = _scared_;



  /////////////////////// Hang /////////////////////////
  react_DB[_achiever_][_positive_][_hang_] = _scared_;
  react_DB[_achiever_][_neutral_][_hang_] = _anger_;
  react_DB[_achiever_][_negative_][_hang_] = _superanger_;

  react_DB[_balanced_][_positive_][_hang_] = _scared_;
  react_DB[_balanced_][_neutral_][_hang_] = _scared_;
  react_DB[_balanced_][_negative_][_hang_] = _annoyed_;

  react_DB[_creative_][_positive_][_hang_] = _scared_;
  react_DB[_creative_][_neutral_][_hang_] = _scared_;
  react_DB[_creative_][_negative_][_hang_] = _anger_;

  react_DB[_distressed_][_positive_][_hang_] = _scared_;
  react_DB[_distressed_][_neutral_][_hang_] = _sad_;
  react_DB[_distressed_][_negative_][_hang_] = _anger_;


  /////////////////////// Shake /////////////////////////
  react_DB[_achiever_][_positive_][_shake_] = _scared_;
  react_DB[_achiever_][_neutral_][_shake_] = _anger_;
  react_DB[_achiever_][_negative_][_shake_] = _superanger_;

  react_DB[_balanced_][_positive_][_shake_] = _scared_;
  react_DB[_balanced_][_neutral_][_shake_] = _scared_;
  react_DB[_balanced_][_negative_][_shake_] = _annoyed_;

  react_DB[_creative_][_positive_][_shake_] = _scared_;
  react_DB[_creative_][_neutral_][_shake_] = _scared_;
  react_DB[_creative_][_negative_][_shake_] = _anger_;

  react_DB[_distressed_][_positive_][_shake_] = _scared_;
  react_DB[_distressed_][_neutral_][_shake_] = _sad_;
  react_DB[_distressed_][_negative_][_shake_] = _anger_;



  /////////////////////// Idle /////////////////////////
  react_DB[_achiever_][_positive_][_idle_] = _calm_;
  react_DB[_achiever_][_neutral_][_idle_] = _calm_;
  react_DB[_achiever_][_negative_][_idle_] = _calm_;

  react_DB[_balanced_][_positive_][_idle_] = _calm_;
  react_DB[_balanced_][_neutral_][_idle_] = _calm_;
  react_DB[_balanced_][_negative_][_idle_] = _calm_;

  react_DB[_creative_][_positive_][_idle_] = _calm_;
  react_DB[_creative_][_neutral_][_idle_] = _calm_;
  react_DB[_creative_][_negative_][_idle_] = _calm_;

  react_DB[_distressed_][_positive_][_idle_] = _calm_;
  react_DB[_distressed_][_neutral_][_idle_] = _calm_;
  react_DB[_distressed_][_negative_][_idle_] = _calm_;
  ////////////////////// call by name //////////////////////
  react_DB[_achiever_][_positive_][_call_] = _calm_;
  react_DB[_achiever_][_neutral_][_call_] = _calm_;
  react_DB[_achiever_][_negative_][_call_] = _calm_;

  react_DB[_balanced_][_positive_][_call_] = _calm_;
  react_DB[_balanced_][_neutral_][_call_] = _calm_;
  react_DB[_balanced_][_negative_][_call_] = _calm_;

  react_DB[_creative_][_positive_][_call_] = _calm_;
  react_DB[_creative_][_neutral_][_call_] = _calm_;
  react_DB[_creative_][_negative_][_call_] = _calm_;

  react_DB[_distressed_][_positive_][_call_] = _calm_;
  react_DB[_distressed_][_neutral_][_call_] = _calm_;
  react_DB[_distressed_][_negative_][_call_] = _calm_;


  ////////////////////// user recognised //////////////////////
  react_DB[_achiever_][_positive_][_recognized_] = _calm_;
  react_DB[_achiever_][_neutral_][_recognized_] = _calm_;
  react_DB[_achiever_][_negative_][_recognized_] = _calm_;

  react_DB[_balanced_][_positive_][_recognized_] = _calm_;
  react_DB[_balanced_][_neutral_][_recognized_] = _calm_;
  react_DB[_balanced_][_negative_][_recognized_] = _calm_;

  react_DB[_creative_][_positive_][_recognized_] = _calm_;
  react_DB[_creative_][_neutral_][_recognized_] = _calm_;
  react_DB[_creative_][_negative_][_recognized_] = _calm_;

  react_DB[_distressed_][_positive_][_recognized_] = _calm_;
  react_DB[_distressed_][_neutral_][_recognized_] = _calm_;
  react_DB[_distressed_][_negative_][_recognized_] = _calm_;


  ////////////////////// Hand Massage //////////////////////
  react_DB[_achiever_][_positive_][_handmassage_] = _affectionate_;
  react_DB[_achiever_][_neutral_][_handmassage_] = _curious_;
  react_DB[_achiever_][_negative_][_handmassage_] = _calm_;

  react_DB[_balanced_][_positive_][_handmassage_] = _happy_;
  react_DB[_balanced_][_neutral_][_handmassage_] = _excited_;
  react_DB[_balanced_][_negative_][_handmassage_] = _calm_;

  react_DB[_creative_][_positive_][_handmassage_] = _excited_;
  react_DB[_creative_][_neutral_][_handmassage_] = _curious_;
  react_DB[_creative_][_negative_][_handmassage_] = _calm_;

  react_DB[_distressed_][_positive_][_handmassage_] = _affectionate_;
  react_DB[_distressed_][_neutral_][_handmassage_] = _curious_;
  react_DB[_distressed_][_negative_][_handmassage_] = _calm_;

    ////////////////////// Head Massage //////////////////////
  react_DB[_achiever_][_positive_][_headmassage_] = _affectionate_;
  react_DB[_achiever_][_neutral_][_headmassage_] = _curious_;
  react_DB[_achiever_][_negative_][_headmassage_] = _calm_;

  react_DB[_balanced_][_positive_][_headmassage_] = _happy_;
  react_DB[_balanced_][_neutral_][_headmassage_] = _excited_;
  react_DB[_balanced_][_negative_][_headmassage_] = _calm_;

  react_DB[_creative_][_positive_][_headmassage_] = _happy_;
  react_DB[_creative_][_neutral_][_headmassage_] = _affectionate_;
  react_DB[_creative_][_negative_][_headmassage_] = _calm_;

  react_DB[_distressed_][_positive_][_headmassage_] = _superhappy_;
  react_DB[_distressed_][_neutral_][_headmassage_] = _playful_;
  react_DB[_distressed_][_negative_][_headmassage_] = _curious_;


      ////////////////////// Belly Massage //////////////////////
  react_DB[_achiever_][_positive_][_bellymassage_] = _affectionate_;
  react_DB[_achiever_][_neutral_][_bellymassage_] = _curious_;
  react_DB[_achiever_][_negative_][_bellymassage_] = _calm_;

  react_DB[_balanced_][_positive_][_bellymassage_] = _happy_;
  react_DB[_balanced_][_neutral_][_bellymassage_] = _excited_;
  react_DB[_balanced_][_negative_][_bellymassage_] = _calm_;

  react_DB[_creative_][_positive_][_bellymassage_] = _excited_;
  react_DB[_creative_][_neutral_][_bellymassage_] = _curious_;
  react_DB[_creative_][_negative_][_bellymassage_] = _calm_;

  react_DB[_distressed_][_positive_][_bellymassage_] = _affectionate_;
  react_DB[_distressed_][_neutral_][_bellymassage_] = _curious_;
  react_DB[_distressed_][_negative_][_bellymassage_] = _calm_;




      ////////////////////// Back Massage //////////////////////
  react_DB[_achiever_][_positive_][_backmassage_] = _affectionate_;
  react_DB[_achiever_][_neutral_][_backmassage_] = _curious_;
  react_DB[_achiever_][_negative_][_backmassage_] = _calm_;

  react_DB[_balanced_][_positive_][_backmassage_] = _happy_;
  react_DB[_balanced_][_neutral_][_backmassage_] = _excited_;
  react_DB[_balanced_][_negative_][_backmassage_] = _calm_;

  react_DB[_creative_][_positive_][_backmassage_] = _excited_;
  react_DB[_creative_][_neutral_][_backmassage_] = _curious_;
  react_DB[_creative_][_negative_][_backmassage_] = _calm_;

  react_DB[_distressed_][_positive_][_backmassage_] = _affectionate_;
  react_DB[_distressed_][_neutral_][_backmassage_] = _curious_;
  react_DB[_distressed_][_negative_][_backmassage_] = _calm_;

}