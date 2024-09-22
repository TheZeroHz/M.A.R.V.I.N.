/*
********************************************************************************************
********************************************************************************************
!!                              React Generator for Robots                                !!
!!                                    -:Developed By:-                                    !!
!!                                                                                        !!
!!                             Md. Rakibul Hasan || TheZeroHz                             !!
!!                          Github: https://github.com/TheZeroHz                          !!
!!                              Last Updated: 17 March,2024                               !!
********************************************************************************** V-1.0 ***
********************************************************************************************
*/


#ifndef REACTGENERATOR_H
#define REACTGENERATOR_H
#include<Arduino.h>
#include<esp_random.h>
#include "smaPersonality.h"
#include "Vector.h"
#include "rewardDB.h"
#include "reactDB.h"
#include "CLI.h"
class ReactGenerator {
private:
    rewardDB rwdDB;
    reactDB rctDB;
    SMA smaAttitude;
    Vector<Reaction> reaction_logs;
    Vector<Mood> mood_logs;    
    int _WindowSize_=default_WindowSize;
    int _FrameSize_=default_FrameSize; 
public:
    CLI CMD;
    Vector<double> reward_logs;
    CharacterState character;
    double reward_Multiplier[num_of_personality];
    int moodChangeCounter=0;
    ReactGenerator();
    void setFrameSize(int _size_);
    int getFrameSize();
    void setWindowSize(int _size_);
    int getWindowSize();

    void slideWindow(Vector<double> &arr, int _frameSize_, int _windowSize_);   
    void setReaction(Personality p, Mood m, Action a, Reaction e);
    Reaction getReaction(Personality p, Mood m, Action a);
    char *reactionName(Reaction R);
    void addReactionLogs(Reaction R);
    Reaction getReactionLog(int index);
    int getReactionLogsCount();
    void showReactionLogs();
    

    void setRewardMultiplier(double achiever,double balanced,double creative,double distressed);
    void addRewardLogs(double x);
    double getRewardLog(int index);
    Vector<double> getRewardLog();
    int getRewardLogsCount();
    void showRewardLogs();
    
    Mood predictMood();
    char *moodName(Mood M);
    void showMoodDetails();
    void addMoodLogs(Mood M);
    void showMoodLogs();
    Mood getMoodLog(int index);
    int getMoodLogsCount();

    Personality predictPersonality();
    char *personalityName(Personality P);
    
    char * getActionName(Action action);
    Action getActionByName(const char* actionName);
};

#endif /* REACTGENERATOR_H */

