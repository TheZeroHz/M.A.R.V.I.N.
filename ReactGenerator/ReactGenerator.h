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
#include "Vector.h"
#include "rewardDB.h"
#include "reactDB.h"
#include "CLI.h"
class ReactGenerator {
private:
    rewardDB rwdDB;
    reactDB rctDB;
    CLI CMD;
    Vector<double> reward_logs;
    Vector<Reaction> reaction_logs;
    int _WindowSize_=default_WindowSize;
    
public:
    CharacterState character;
    double reward_Multiplier[num_of_personality];
    
    ReactGenerator();
    void setWindowSize(int _Min_,int _Max_);
    int getWindowSize();
    
    void setReaction(Personality p, Mood m, Action a, Reaction e);
    Reaction getReaction(Personality p, Mood m, Action a);
    char *reactionName(Reaction R);
    void addReactionLogs(Reaction R);
    Reaction getReactionLog(int index);
    int getReactionLogsCount();
    

    void setRewardMultiplier(double achiever,double balanced,double creative,double distressed);
    void addRewardLogs(double x);
    double getRewardLog(int index);
    Vector<double> getRewardLog();
    int getRewardLogsCount();
    void showRewardLogs();
    
    Mood predictMood();
    char *moodName(Mood M);
};

#endif /* REACTGENERATOR_H */

