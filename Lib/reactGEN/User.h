#ifndef USER_H
#define USER_H
#include<Arduino.h>
#include"RG_config.h"
struct Person{
  int id;
  int Rating;
  Reaction lastReaction;
  String name;
  String role;
};
class User{
private:
Person info;
public:
Person searchById(int id);
bool add(Person newUser);
};

#endif