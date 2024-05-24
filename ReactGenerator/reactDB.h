#ifndef REACTDB_H
#define REACTDB_H
#include "RG_config.h"
class reactDB{
  public:
  Reaction react_DB[num_of_personality][num_of_mood][num_of_action];
  void load(LoadFrom loader);
  char* datapoint_Name(Reaction r);
};
#endif