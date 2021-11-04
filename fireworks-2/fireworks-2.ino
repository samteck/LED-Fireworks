#include <FastLED.h>
#define NUM_LEDS 120
#define DATA_PIN 7
#define COLOR_ORDER GRB 
#define LED_TYPE WS2812B
#define NUM_SPARKS 120
CRGB leds[NUM_LEDS];
float sparkPos[NUM_SPARKS];
float sparkVel[NUM_SPARKS];
float sparkCol[NUM_SPARKS];
float gravity = -.0019;
float dying_gravity = gravity;
float c1 = 20;
float c2 = 25;
float flarePos;

void setup() {
  
  delay(2000);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
}

void loop() {

  flare();
  explodeLoop0();
  delay(10);
  flare();
  explodeLoop1();
  delay(10);
  flare();
  explodeLoop2();
  delay(10);
  flare();
  explodeLoop3();
  delay(10);
  flare();
  explodeLoop4();
  delay(10);
}

void flare() {
  
  flarePos = 0;
  float flareVel = float(random16(60, 80)) / 90;
  float brightness = 1;

    for (int i = 0; i < 5; i++) { 
      sparkPos[i] = 0; sparkVel[i] = (float(random8()) / 255) * (flareVel / 5);
      sparkCol[i] = sparkVel[i] * 1000;
      sparkCol[i] = constrain(sparkCol[i], 0, 255); } 
  FastLED.clear(); while (flareVel >= -.05) {
    for (int i = 0; i < 5; i++) {
      sparkPos[i] += sparkVel[i];
      sparkPos[i] = constrain(sparkPos[i], 0, 120);
      sparkVel[i] += gravity;
      sparkCol[i] += -.8;
      sparkCol[i] = constrain(sparkCol[i], 0, 255);
      leds[int(sparkPos[i])] = HeatColor(sparkCol[i]);
      leds[int(sparkPos[i])] %= 50; 
    }
   leds[int(flarePos)] = CHSV(0, 0, int(brightness * 255));
   FastLED.show();
   FastLED.clear();
   flarePos += flareVel;
   flareVel += gravity;
   brightness *= .99;
  }
}

void explodeLoop0() {
  
  int gSparks = flarePos / 2;
  for (int i = 0; i < gSparks; i++) { 
    sparkPos[i] = flarePos; sparkVel[i] = (float(random16(0, 20000)) / 10000.0) - 1.0;
    sparkCol[i] = abs(sparkVel[i]) * 500;
    sparkCol[i] = constrain(255, 0, sparkCol[i]);
    sparkVel[i] *= flarePos / NUM_LEDS;
  }
  sparkCol[0] = 255;
  while(sparkCol[0] > c2/128) { 
    FastLED.clear();
      for (int i = 0; i < gSparks; i++) { 
      sparkPos[i] += sparkVel[i]; 
      sparkPos[i] = constrain(sparkPos[i], 0, NUM_LEDS); 
      sparkVel[i] += dying_gravity; 
      sparkCol[i] *= .99; 
      sparkCol[i] = constrain(255, 0, sparkCol[i]);  
      if(sparkCol[i] > c1) { 
        leds[int(sparkPos[i])] = CRGB((255 * (sparkCol[i] - c1)) / (255 - c1), 255, 255);
      }
      else if (sparkCol[i] < c2) { 
        leds[int(sparkPos[i])] = CRGB(0, (255 * sparkCol[i]) / c2, 0) ;
      }
      else { 
        leds[int(sparkPos[i])] = CRGB(0, 255, (255 * (sparkCol[i] - c2)) / (c1 - c2));
      }
    }
    dying_gravity *= .985;
    FastLED.show();
  }
  FastLED.clear();
  FastLED.show();
}

void explodeLoop1() {
  
  int sSparks = flarePos / 2;
  for (int i = 0; i < sSparks; i++) { 
    sparkPos[i] = flarePos; sparkVel[i] = (float(random16(0, 20000)) / 10000.0) - 1.0; 
    sparkCol[i] = abs(sparkVel[i]) * 500;  
    sparkCol[i] = constrain(sparkCol[i], 0, 255); 
    sparkVel[i] *= flarePos / NUM_LEDS;
  } 
  sparkCol[0] = 255; 
  while(sparkCol[0] > c2/128) { 
    FastLED.clear();
      for (int i = 0; i < sSparks; i++) { 
      sparkPos[i] += sparkVel[i]; 
      sparkPos[i] = constrain(sparkPos[i], 0, NUM_LEDS); 
      sparkVel[i] += dying_gravity; 
      sparkCol[i] *= .99; 
      sparkCol[i] = constrain(sparkCol[i], 0, 255);  
      if(sparkCol[i] > c1) { 
        leds[int(sparkPos[i])] = CRGB(random8(180), random8(180), (255 * (sparkCol[i] - c1)) / (255 - c1));
      }
      else if (sparkCol[i] < c2) { 
        leds[int(sparkPos[i])] = CRGB((255 * sparkCol[i]) / c2, random8(8), random8(8));
      }
      else { 
        leds[int(sparkPos[i])] = CRGB(random8(80), (255 * (sparkCol[i] - c2)) / (c1 - c2), random8(18));
      }
    }
    dying_gravity *= .985;
    FastLED.show();
  }
  FastLED.clear();
  FastLED.show();
}

void explodeLoop2() {
  
  int rSparks = flarePos / 2;
  for (int i = 0; i < rSparks; i++) { 
    sparkPos[i] = flarePos; sparkVel[i] = (float(random16(0, 20000)) / 10000.0) - 1.0; 
    sparkCol[i] = abs(sparkVel[i]) * 500;  
    sparkCol[i] = constrain(sparkCol[i], 0, 255); 
    sparkVel[i] *= flarePos / NUM_LEDS; 
  }
  sparkCol[0] = 255; 
  while(sparkCol[0] > c2/128) { 
    FastLED.clear();
    for (int i = 0; i < rSparks; i++) { 
      sparkPos[i] += sparkVel[i]; 
      sparkPos[i] = constrain(sparkPos[i], 0, NUM_LEDS); 
      sparkVel[i] += dying_gravity; 
      sparkCol[i] *= .99; 
      sparkCol[i] = constrain(sparkCol[i], 0, 255);  
      if(sparkCol[i] > c1) { 
        leds[int(sparkPos[i])] = CRGB(255, 255, (255 * (sparkCol[i] - c1)) / (255 - c1));
      }
      else if (sparkCol[i] < c2) { 
        leds[int(sparkPos[i])] = CRGB((255 * sparkCol[i]) / c2, 0, 0);
      }
      else { 
        leds[int(sparkPos[i])] = CRGB(255, (255 * (sparkCol[i] - c2)) / (c1 - c2), 0);
      }
    }
    dying_gravity *= .985;
    FastLED.show();
  }
  FastLED.clear();
  FastLED.show();
}

void explodeLoop3() {
  
  int bSparks = flarePos / 2;
    for (int i = 0; i < bSparks; i++) { 
    sparkPos[i] = flarePos; sparkVel[i] = (float(random16(0, 20000)) / 10000.0) - 1.0; 
    sparkCol[i] = abs(sparkVel[i]) * 500;  
    sparkCol[i] = constrain(0, sparkCol[i], 255); 
    sparkVel[i] *= flarePos / NUM_LEDS; 
  }
  sparkCol[0] = 255; 
  while(sparkCol[0] > c2/128) { 
    FastLED.clear();
    for (int i = 0; i < bSparks; i++) { 
      sparkPos[i] += sparkVel[i]; 
      sparkPos[i] = constrain(sparkPos[i], 0, NUM_LEDS); 
      sparkVel[i] += dying_gravity; 
      sparkCol[i] *= .99; 
      sparkCol[i] = constrain(0, sparkCol[i], 255);  
      if(sparkCol[i] > c1) { 
        leds[int(sparkPos[i])] = CRGB(255, (255 * (sparkCol[i] - c1)) / (255 - c1), 255);
      }
      else if (sparkCol[i] < c2) { 
        leds[int(sparkPos[i])] = CRGB(0, 0, (255 * sparkCol[i]) / c2);
      }
      else { 
        leds[int(sparkPos[i])] = CRGB((255 * (sparkCol[i] - c2)) / (c1 - c2), 0, 255);
      }
    }
    dying_gravity *= .985;
    FastLED.show();
  }
  FastLED.clear();
  FastLED.show();
}

void explodeLoop4() {
  
  int xSparks = flarePos / 2;
  for (int i = 0; i < xSparks; i++) { 
    sparkPos[i] = flarePos; sparkVel[i] = (float(random16(0, 20000)) / 10000.0) - 1.0; 
    sparkCol[i] = abs(sparkVel[i]) * 500;  
    sparkCol[i] = constrain(0, sparkCol[i], 255); 
    sparkVel[i] *= flarePos / NUM_LEDS; 
  }
  sparkCol[0] = 255; 
  while(sparkCol[0] > c2/128) { 
    FastLED.clear();
      for (int i = 0; i < xSparks; i++) { 
      sparkPos[i] += sparkVel[i]; 
      sparkPos[i] += sparkVel[i]; 
      sparkPos[i] = constrain(sparkPos[i], 0, NUM_LEDS); 
      sparkVel[i] += dying_gravity; 
      sparkCol[i] *= .99; 
      sparkCol[i] = constrain(255, 0, sparkCol[i]);  
      if(sparkCol[i] > c1) { 
        leds[int(sparkPos[i])] = CRGB((255 * (sparkCol[i] - c1)) / (255 - c1), random8(sparkCol[i] + c2), random8(150));
      }
      else if (sparkCol[i] < c2) { 
        leds[int(sparkPos[i])] = CRGB(random16(5, 10), (255 * sparkCol[i]) / c2, random8(2)>1) ;
      }
      else { 
        leds[int(sparkPos[i])] = CRGB(random8(c2), random8(90), (255 * (sparkCol[i] - c2)) / (c1 - c2));
      }
    }
    dying_gravity *= .985;
    FastLED.show();
  }
  FastLED.clear();
  FastLED.show();
}
