#define EIDSP_QUANTIZE_FILTERBANK 0
#include "CONFIGS.h"
#include "MARVIN_WAKEWORD.h"
#include "ESpeech.h"
#include "GeminiESP32.h"
#include "CoreEngine.h"
#include "FFat.h"
#include "AdditonalTask.h"



ESpeech STT(I2S_NUM_1,I2S__SCK,I2S__WS,I2S__SD);
GeminiESP32 assistant(GEMINI_API_TOKEN);
AdditionalTask additionalTask;

void setup() {
  Serial.begin(115200);Serial.println(F(".....MARVIN BOOTING..."));
  FFat.begin(true);
  WiFi.begin("Rakib","rakib@2024");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
  }
  Serial.println("\nConnected");
  audioInit();
  initwakeword();
  STT.begin(serverUrl);
  additionalTask.begin();  // Initialize WiFiManager task
}

void loop() {

  if (detected()) {
    if (inference.buffer != NULL) {
    free(inference.buffer);  // Free the allocated memory previously allocated in rtos task
    inference.buffer = NULL; // Set the pointer to NULL to avoid dangling pointers
    record_status = false;
    }
    //Serial.printf("Free Heap after detection: %d\n", ESP.getFreeHeap());
    STT.recordAudio();
    //Serial.printf("Free Heap after stt record: %d\n", ESP.getFreeHeap());
    String intent=STT.getTranscription();
    String intent2=intent;
    Serial.println(intent);
    CoreEngine core;
    
    core.addCommasToLocalCommand(intent);
    core.processLocalCommand(intent);
    core.addCommasToCommand(intent2);
    core.processCommand(intent2);
    

    if(!core.getLocalCmd().isEmpty()){  //MOVEMENT CMD
    Serial.println("Local CMD:"+core.getLocalCmd());
    }

    if(!core.getCloudCmd().isEmpty()){   //FIREBASE CMD
    Serial.println("Cloud CMD:"+core.getCloudCmd());
    //additionalTask.SEND_TO_FIREBASE(core.getCloudCmd());
    }


    if(core.getCloudCmd().isEmpty()&&core.getLocalCmd().isEmpty()){
      //first Search In LoaclDB Then LLM
    String answer=assistant.askQuestion(intent);
    Serial.println("Answer from GEMINI:=>"+answer);
    audioConnecttoSpeech(answer.c_str(), "en");
    }
    core.resetLocalCmd();
    core.resetCloudCmd();

    ei_sleep(500);
    if (microphone_inference_start(EI_CLASSIFIER_RAW_SAMPLE_COUNT) == false) {
    ei_printf("ERR: Could not allocate audio buffer (size %d), this could be due to the window length of your model\r\n", EI_CLASSIFIER_RAW_SAMPLE_COUNT);
     }
    }
}




