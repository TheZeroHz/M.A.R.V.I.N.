#ifndef ADDITIONALTASK_H
#define ADDITIONALTASK_H
#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <addons/RTDBHelper.h>
#include "CONFIGS.h"
#include "TTP223Touch.h"
class AdditionalTask {
public:
bool sendFDB=false;
String strFDBData="";
TTP223Touch bellyT;
void SET_UP();
void LOOPER();
void SEND_TO_FIREBASE(String Data);
void roboCMD(String command); 
void begin();
static TaskHandle_t Task;
private:
  static void TaskWrapper(void *pvParameters) {
    AdditionalTask *instance = static_cast<AdditionalTask *>(pvParameters);
    instance->LOOPER();
  }
};

void AdditionalTask::begin(){
    xTaskCreatePinnedToCore(
      TaskWrapper,    // Task function (wrapper for static method)
      "Task",         // Task name
      WM_STACK_SIZE,  // Stack size (in bytes)
      this,           // Pass class instance as task parameter
      WM_PRIORITY,    // Task priority
      &Task,          // Task handle
      WM_CORE         // Core to run the task on (core WM_CORE)
    );
}

void AdditionalTask::SET_UP(){
bellyT.setting(BellyTouchPin,2000);
bellyT.begin();
}


void AdditionalTask::LOOPER(){
    SET_UP();
    while (true) {
      if(sendFDB){
        //Serial.printf("Sending Data... %s\n", Firebase.setString(fbdo, "/test/tag",strFDBData) ? "ok" : fbdo.errorReason().c_str());
        sendFDB=false;
        strFDBData="";
      }
      if(bellyT.isTouchHeld())Serial.println("HOLD BELLY");
           vTaskDelay(10 / portTICK_PERIOD_MS);
    }

}

void AdditionalTask::SEND_TO_FIREBASE(String Data){
  if(!sendFDB){
  strFDBData=Data;
  sendFDB=true;}
}


// Initialize the static task handle
TaskHandle_t AdditionalTask::Task = nullptr;
void AdditionalTask::roboCMD(String command){}


#endif  // ADDITIONALTASK_H
