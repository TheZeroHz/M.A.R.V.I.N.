#ifndef TTP223TOUCH_H
#define TTP223TOUCH_H

#include <Arduino.h>

class TTP223Touch {
  private:
    int pin;                  // Pin connected to the TTP223 module
    unsigned long holdTime;   // Time threshold for detecting touch hold
    unsigned long startTime;  // Start time when touch is first detected
    bool isTouch;           // State of the touch (true if touched, false otherwise)
  public:
    void setting(int pinn, unsigned long holdTimee);
    void begin();
    bool isTouched();
    bool isTouchHeld();
};

#endif
