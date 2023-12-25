#define USE_DMA
#include "allframe.h"
#include <TJpg_Decoder.h>
#ifdef USE_DMA
  uint16_t  dmaBuffer1[16*16];
  uint16_t  dmaBuffer2[16*16];
  uint16_t* dmaBufferPtr = dmaBuffer1;
  bool dmaBufferSel = 0;
#endif
#include "SPI.h"
#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();

bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
{
  if ( y >= tft.height() ) return 0;
#ifdef USE_DMA
  if (dmaBufferSel) dmaBufferPtr = dmaBuffer2;
  else dmaBufferPtr = dmaBuffer1;
  tft.pushImageDMA(x, y, w, h, bitmap, dmaBufferPtr);
#else
  tft.pushImage(x, y, w, h, bitmap);
#endif
  return 1;
}

void setup()
{
  Serial.begin(115200);
  Serial.println("\n\n Testing TJpg_Decoder library");
  tft.begin();
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(3);
#ifdef USE_DMA
  tft.initDMA();
#endif
  TJpgDec.setJpgScale(1);
  tft.setSwapBytes(true);
  TJpgDec.setCallback(tft_output);
}

void loop()
{
  uint16_t w = 0, h = 0;
  TJpgDec.getJpgSize(&w, &h, cry_0_a, sizeof(cry_0_a));
  Serial.print("Width = "); Serial.print(w); Serial.print(", height = "); Serial.println(h);
  uint32_t dt = millis();
  tft.startWrite();
  TJpgDec.drawJpg(0, 0, cry_0_a, sizeof(cry_0_a));
  TJpgDec.drawJpg(0, 0, cry_1_a, sizeof(cry_1_a));
  TJpgDec.drawJpg(0, 0, cry_2_a, sizeof(cry_2_a));
  TJpgDec.drawJpg(0, 0, cry_3_a, sizeof(cry_3_a));
  TJpgDec.drawJpg(0, 0, cry_4_a, sizeof(cry_4_a));
  TJpgDec.drawJpg(0, 0, cry_5_a, sizeof(cry_5_a));
  TJpgDec.drawJpg(0, 0, cry_6_a, sizeof(cry_6_a));
  TJpgDec.drawJpg(0, 0, cry_7_a, sizeof(cry_7_a));
  TJpgDec.drawJpg(0, 0, cry_8_a, sizeof(cry_8_a));
  TJpgDec.drawJpg(0, 0, cry_9_a, sizeof(cry_9_a));
  TJpgDec.drawJpg(0, 0, cry_10_a, sizeof(cry_10_a));
  tft.endWrite();
  dt = millis() - dt;
  Serial.print(dt); Serial.println(" ms");
}
