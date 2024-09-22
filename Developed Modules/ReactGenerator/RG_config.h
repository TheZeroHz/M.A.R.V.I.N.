#ifndef RG_CONFIG_H
#define RG_CONFIG_H
#define USE_CLI // If you want to use uncomment this
#ifdef USE_CLI
#include "CLI.h"
#endif

//$$ Make Sure All these enum declaration have that certain amount of datapoint $$//
#define num_of_personality 4
#define num_of_mood 3
#define num_of_action 14
#define num_of_reaction 17

#define default_FrameSize 20
#define default_WindowSize 4
#define reward_multiplier_randomness 10.5 //in percentage

struct reward_values {
  double val[num_of_reaction];
};

enum LoadFrom{
  _FLASH_,
  _SPIFF_,
  _APP_,
  _CLOUD_
};

/**/
enum Task{
  _sing_,
  _dance_,
  _playwin_,
  _playlose_,
  _sleep_,
  _fire_,
  _bore_,
  _spit_,
};


/*
Achiever: Predominantly positive moods

Creative: A mix of moods, with a slight tilt towards positive and neutral

Balanced: An even distribution of positive, negative, and neutral moods

Distressed: Predominantly negative moods
*/
enum Personality { _achiever_,
                   _creative_,
                   _balanced_, 
                   _distressed_,
};

/*
Normal: React Normally
Phyco: React Abnormally
*/

enum MentalState{
  _normal_,
  _phyco_,
};


enum Mood { _positive_,
            _neutral_,
            _negative_,
};

enum Inertia{ _HighInertia_,
              _LowInertia_
};
enum Action { _hithead_,
              _hitbelly_,
              _hithand_,
              _hitback_,
              _fall_,
              _hang_,
              _shake_,
              _idle_,
              _call_,
              _recognized_,
              _handmassage_,
              _headmassage_,
              _bellymassage_,
              _backmassage_,
};
enum Reaction {
  _superanger_,
  _anger_,
  _supersad_,
  _sad_,
  _annoyed_,
  _frustrated_,
  _scared_,
  _confused_,
  _calm_,
  _shy_,
  _curious_,
  _excited_,
  _surprised_,
  _playful_,
  _affectionate_,
  _happy_,
  _superhappy_
};

struct CharacterState {
  Personality _personality_;
  Mood _mood_;
  Reaction _reaction_;
  Inertia _inertia_;
  double MoodPositivity = 0.5, MoodNegativity = -0.5;
  bool moodChanged=false;
};
#endif