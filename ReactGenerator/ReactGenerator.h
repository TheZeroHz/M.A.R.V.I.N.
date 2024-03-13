#ifndef REACTGENERATOR_H
#define REACTGENERATOR_H
#include<Arduino.h>
// Define the enums
enum Personality {
    _achiever_,
    _balanced_,
    _creative_,
    _distressed_,
};

enum Mood {
    _positive_,
    _neutral_,
    _negative_,
};

enum Action {
    _hithead_,
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
    double _mfactor_=0,_pfactor_=0;
    double _pchanges_=0, _nchanges_=0;
};

class ReactGenerator {
private:
    int count_RL_loop=0;
    static const int personalityCount = _distressed_ + 1;
    static const int moodCount = _negative_ + 1;
    static const int actionCount = _backmassage_ + 1;
    Reaction tiny_DB[personalityCount][moodCount][actionCount];
    double moodchangefactor;
    double personalitychangefactor;

public:
    double changeSPEED=1;
    CharacterState character;
    ReactGenerator();
    Reaction getReaction(Personality p, Mood m, Action a);
    void setReaction(Personality p, Mood m, Action a, Reaction e);
    void adjustReinforcement(Action a);
    char *reactionName(Reaction E);
};

#endif /* REACTGENERATOR_H */

