/*
********************************************************************************************
********************************************************************************************
!!                            Command Line Interface for Robots                           !!
!!                                    -:Developed By:-                                    !!
!!                                                                                        !!
!!                             Md. Rakibul Hasan || TheZeroHz                             !!
!!                          Github: https://github.com/TheZeroHz                          !!
!!                              Last Updated: 17 March,2024                               !!
********************************************************************************* V-1.0 ****
********************************************************************************************
*/

#ifndef CLI_H
#define CLI_H
#include"Arduino.h" 
#include "Vector.h"
class CLI{
public:
// Function to print all elements of a Vector
void showDoubleVec(Vector<double> &vec);
template<typename T>
void show(const T& value);
void nl();
};
#endif