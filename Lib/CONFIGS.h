#ifndef CONFIGS_H
#define CONFIGS_H
#define UPLOAD_BODY

#include<Arduino.h>
#include "multiTASK/espnowTASK.h"

#ifdef UPLOAD_HEAD
//#include "multiTASK/camTASK.h"
#include "multiTASK/animatorTASK.h"
#endif


#ifdef UPLOAD_BODY
#include "reactGEN/ReactGenerator.h"
#include "actuator/Marvin.h"
#include "multiTASK/audioTASK.h"
#endif



// #######   WIFI MANAGER CONFIG#######
#define WM_TRIGGER_PIN 0        // Pin to trigger configuration portal
#define WIFI_CHECK_DELAY 10  // Delay to prevent task hogging (ms)
#define WM_CORE 0            // Core to run the WiFiManager task
#define WM_STACK_SIZE 16000   // Stack size for WiFiManager task
#define WM_PRIORITY 1        // Task priority
#define WMAP_SSID "M.A.R.V.I.N." /// SSID Of Config Portal
#define WMAP_PASS "bubt1234" ///PassWord Of Config Portal
#define WM_TIME_OUT 90 ///Automatically Close WIFI Portal after 90s
#define DONT_BLOCK false /// Don't block the CPU If WIFI Not Connected
#define BLOCK true /// Block CPU If Wifi Not Connected

//######### THRESHOLD FOR TRIGGER MARVIN #####
#define WAKEWORD_DETECTION_THRESHOLD 0.9


//######## PINS FOR MICROPHONE I2S ##########
#define I2S__WS 16
#define I2S__SD 7
#define I2S__SCK 15

///##### STT SERVER IP ADDRESS #######
const char* serverUrl = "http://192.168.0.106:8888/uploadAudio";  // Change the IP Address according To Your Server's config

//###### API KEY FOR YOUR GEMINI ########
#define GEMINI_API_TOKEN "AIzaSyDPNTBZEBFmlZBIStC-ExslDAMQPudkuOE"

//###### FireBase DataBase URL ###########
#define DATABASE_URL "dream-palace-37cf0-default-rtdb.firebaseio.com" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app


//######## PINS FOR MARVINS TOUCH SENSOR #########
//#define HeadTouch wronggg pcb error
const int BellyTouchPin = 8;
const int BackTouchPin = 3;
const int LeftHandTouchPin = 18;
const int RightHandTouchPin = 17;



//######## PINS FOR MARVINS SERVO MOTORS #########
#define LeftLeg 21 
#define RightLeg 47
#define LeftFoot 48
#define RightFoot 45 
#define RightHand 20
#define LeftHand 19
#define Head 38

#endif