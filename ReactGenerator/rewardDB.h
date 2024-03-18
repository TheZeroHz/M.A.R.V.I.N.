#ifndef REWARDDB_H
#define REWARDDB_H
#include "RG_config.h"
class rewardDB{
  public:
  reward_values reward_DB[num_of_personality];
  void load(LoadFrom loader);
};
#endif