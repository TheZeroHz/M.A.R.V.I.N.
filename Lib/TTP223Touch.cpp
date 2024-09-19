#include "TTP223Touch.h"

// Constructor: Initialize pin and hold time (default 2 seconds)
void TTP223Touch::setting(int pinn, unsigned long holdTimee) {
  pin = pinn;
  holdTime = holdTimee;
  startTime = 0;
  isTouch = false;
}

// Begin: Initialize the pin as input
void TTP223Touch::begin() {
  pinMode(pin, INPUT);
}

// Check if the sensor is currently touched
bool TTP223Touch::isTouched() {
  return digitalRead(pin) == HIGH;
}

// Check if the touch is held for the specified duration
bool TTP223Touch::isTouchHeld() {
  if (isTouched()) {
    // If the touch is detected and start time hasn't been set, set it
    if (startTime == 0) {
      startTime = millis();
    }

    // If the touch has been held long enough, return true
    if (millis() - startTime >= holdTime) {
      isTouch = true;
      return true;
    }
  } else {
    // If touch is not detected, reset the start time
    startTime = 0;
    isTouch = false;
  }

  return false;
}
