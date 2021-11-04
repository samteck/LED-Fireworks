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

  flare(0, 0, 255);
  burst(0, 0, 255);
  flare(0, 255, 0);
  burst(0, 255, 0);
  flare(255, 0, 0);
  burst(255, 0, 0);
  flare(0, 255, 255);
  burst(0, 255, 255);
  flare(255, 0, 255);
  burst(255, 0, 255);
  flare(255, 250, 0);
  burst(255, 250, 0);
  flare(50, 255, 255);
  burst(50, 255, 255);
  flare(255, 50, 150);
  burst(255, 50, 150);
  flare(255, 250, 50);
  burst(255, 250, 50);
}

void flare(int a, int b, int c) {
  for (int i = 7; i <= 89; i++) {
    leds[i] = CRGB(a, b, c);
    leds[i - 1] = CRGB(a * .7, b * .7, c * .7);
    leds[i - 2] = CRGB(a * .7 * .7, b * .7 * .7, c * .7 * .7);
    leds[i - 3] = CRGB(a * .7 * .7 * .7, b * .7 * .7 * .7, c * .7 * .7 * .7);
    leds[i - 4] = CRGB(a * .7 * .7 * .7 * .7, b * .7 * .7 * .7 * .7, c * .7 * .7 * .7 * .7);
    leds[i - 5] = CRGB(a * .7 * .7 * .7 * .7 * .7, b * .7 * .7 * .7 * .7 * .7, c * .7 * .7 * .7 * .7 * .7);
    leds[i - 6] = CRGB(a * .7 * .7 * .7 * .7 * .7 * .7, b * .7 * .7 * .7 * .7 * .7 * .7, c * .7 * .7 * .7 * .7 * .7 * .7);
    //delay();
    FastLED.show();
    leds[i - 7] = CRGB(0, 0, 0);
    FastLED.show();
  }
  FastLED.clear();

  //delay(2000);
}

void burst(int a, int b, int c) {
  for (int i = 90; i <= 119; i++) {
    leds[i] = CRGB(a, b, c);
    leds[i - 1] = CRGB(a * .7, b * .7, c * .7);
    leds[i - 2] = CRGB(a * .7 * .7, b * .7 * .7, c * .7 * .7);
    leds[i - 3] = CRGB(a * .7 * .7 * .7, b * .7 * .7 * .7, c * .7 * .7 * .7);
    leds[i - 4] = CRGB(a * .7 * .7 * .7 * .7, b * .7 * .7 * .7 * .7, c * .7 * .7 * .7 * .7);
    leds[i - 5] = CRGB(a * .7 * .7 * .7 * .7 * .7, b * .7 * .7 * .7 * .7 * .7, c * .7 * .7 * .7 * .7 * .7);
    leds[i - 6] = CRGB(a * .7 * .7 * .7 * .7 * .7 * .7, b * .7 * .7 * .7 * .7 * .7 * .7, c * .7 * .7 * .7 * .7 * .7 * .7);
    leds[i - 7] = CRGB(a * .7 * .7 * .7 * .7 * .7 * .7 * .7, b * .7 * .7 * .7 * .7 * .7 * .7 * .7, c * .7 * .7 * .7 * .7 * .7 * .7 * .7);
    leds[i - 8] = CRGB(a * .7 * .7 * .7 * .7 * .7 * .7 * .7 * .7, b * .7 * .7 * .7 * .7 * .7 * .7 * .7 * .7, c * .7 * .7 * .7 * .7 * .7 * .7 * .7 * .7);
    leds[i - 9] = CRGB(a * .7 * .7 * .7 * .7 * .7 * .7 * .7 * .7 * .7, b * .7 * .7 * .7 * .7 * .7 * .7 * .7 * .7 * .7, c * .7 * .7 * .7 * .7 * .7 * .7 * .7 * .7 * .7);
    delay(20);
    FastLED.show();
    leds[i - 10] = CRGB(0, 0, 0);
    FastLED.show();
  }
  fill_solid(leds, NUM_LEDS, CRGB::Black);
}
