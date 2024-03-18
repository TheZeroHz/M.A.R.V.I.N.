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

#define default_WindowSize 5
#define max_framesize 10
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

enum Personality { _achiever_,
                   _balanced_,
                   _creative_,
                   _distressed_,
};

enum Mood { _positive_,
            _neutral_,
            _negative_,
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
  double positivity = 0, negativity = 0;
};
#endif