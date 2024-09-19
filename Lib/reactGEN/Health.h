#ifndef HEALTH_H
#define HEALTH_H
#include<Arduino.h>
#include "RG_config.h"
class Health{
private:
int PhysicalHealth=0;
int MentalHealth=0;
int Energy=0;
MentalState behaviour;
public:
void load(LoadFrom loader);
void Physical();
Task repairTask();
bool abortCommand();
};
#endif