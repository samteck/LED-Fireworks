#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    120
int count = 1;
int i = 0;
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

}
void loop() {

  leds[3] = CRGB(0, 255, 0);
  FastLED.show();
  delay(10000);


  //// INTERESTING PATTERN 1
  //  leds[i] = CRGB(0, 255, 0);
  //  FastLED.show();
  //  delay(00);
  //  leds[i] = CRGB(0,0,0);
  //  FastLED.show();
  //  i=i+1;
  //  if(i==300){
  //    i=0;}


  //// INTERESTING PATTERN 2
  //for(int i = 0; i <= 89; i++){
  //  leds[i] = CRGB(0, 0, 255);
  //  leds[299-i] = CRGB(0, 0, 255);
  //  delay(100);
  //  FastLED.show();
  //  leds[i] = CRGB(0, 0, 0);
  //  leds[299-i] = CRGB(0, 0, 0);
  //}

  //for(int i = 90; i<119;i++){
  //  leds[i] = CRGB(0, 0, 255);
  //  delay(50);
  //  }


  //// INTERESTING PATTERN 3
  //  for (int i = 99; i >= 0; i--) {
  //    leds[i] = CRGB ( i, i, i);
  //    FastLED.show();
  //    delay(100);
  //  }
  //  for (int i = 99; i >= 0; i--) {
  //    leds[i] = CRGB ( 20, 0, 0);
  //    FastLED.show();
  //    delay(0);
  //  }
  //  for (int i = 0; i <= 99; i++) {
  //    leds[i] = CRGB ( 0, 20, 0);
  //    FastLED.show();
  //    delay(0);
  //  }
  //  for (int i = 99; i >= 0; i--) {
  //    leds[i] = CRGB ( 20, 20, 20);
  //    FastLED.show();
  //    delay(0);
  //  }


  //// INTERESTING PATTERN 4
  //  switch (count) {
  //  case 1:
  //  leds[i] = CRGB(255, 0, 0);
  //  FastLED.show();
  //  delay(00);
  //  leds[i] = CRGB(0,0,0);
  //  FastLED.show();
  //  i=i+1;
  ////  if(i==300){
  ////    i=0;}
  //    break;
  //  case 2:
  //  leds[i] = CRGB(0, 255, 0);
  //  FastLED.show();
  //  delay(00);
  //  leds[i] = CRGB(0,0,0);
  //  FastLED.show();
  //  i=i+1;
  //  if(i==300){
  //    i=0;}
  //    break;
  //  default:
  //    break;
  //}

}
