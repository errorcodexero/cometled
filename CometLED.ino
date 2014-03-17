#include <FastLED.h>
#include <avr/pgmspace.h>

#define NUM_LEDS 22
#define NUM_STRANDS 3

#define DATA_PIN  2
#define DATA_PIN2 3
#define DATA_PIN3 4

int lastRow = 0;
int lastCol = 0;
int direction = 1;
int j = 0;
int i = 0;

CRGB temp;
CRGB leds[NUM_STRANDS][NUM_LEDS];

void Comet();
void scrollup();
void scrolldown();

void setup() {
      
  delay(100);

      FastLED.addLeds<WS2812B, DATA_PIN,  GRB>(leds[0], NUM_LEDS);
      FastLED.addLeds<WS2812B, DATA_PIN2, GRB>(leds[1], NUM_LEDS);
      FastLED.addLeds<WS2812B, DATA_PIN3, GRB>(leds[2], NUM_LEDS);
    
      Comet();
}

void scrolldown() {
  for(j=0; j < NUM_STRANDS; j++) {
        temp = leds[j][NUM_LEDS - 1];
        for(i = NUM_LEDS - 1; i>=1; i--) {
          leds[j][i]=leds[j][i-1];
        }
      leds[j][0]=temp;
      }
}

void scrollup() {
  for(j<= NUM_STRANDS; j >= 0; j++) {
        temp = leds[j][0];
        for(i = NUM_LEDS - 1; i>=0; i--) {
          leds[j][i]=leds[j][i+1];
        }
      leds[j][21]=temp;
     }    
} 

void Comet() {
    leds[0][13] = CRGB::Red;
    leds[0][12] = CRGB::Red;
    leds[0][11] = CRGB::Red;
    leds[0][10] = CRGB::Red;
    leds[0][9] = CRGB::Red;
    leds[0][8] = CRGB::OrangeRed;
    leds[0][7] = CRGB::OrangeRed;
    leds[0][6] = CRGB::OrangeRed;
    leds[0][5] = CRGB::OrangeRed;
    leds[0][4] = CRGB::Orange;
    leds[0][3] = CRGB::Orange;
    leds[0][2] = CRGB::Orange;
    leds[0][1] = CRGB::Yellow;
    leds[0][0] = CRGB::Yellow;
    
    leds[1][13] = CRGB::Red;
    leds[1][12] = CRGB::Red;
    leds[1][11] = CRGB::Red;
    leds[1][10] = CRGB::Red;
    leds[1][9] = CRGB::Red;
    leds[1][8] = CRGB::OrangeRed;
    leds[1][7] = CRGB::OrangeRed;
    leds[1][6] = CRGB::OrangeRed;
    leds[1][5] = CRGB::OrangeRed;
    leds[1][4] = CRGB::Orange;
    leds[1][3] = CRGB::Orange;
    leds[1][2] = CRGB::Orange;
    leds[1][1] = CRGB::Yellow;
    leds[1][0] = CRGB::Yellow;
   
    leds[2][13] = CRGB::Red;
    leds[2][12] = CRGB::Red;
    leds[2][11] = CRGB::Red;
    leds[2][10] = CRGB::Red;
    leds[2][9] = CRGB::Red;
    leds[2][8] = CRGB::OrangeRed;
    leds[2][7] = CRGB::OrangeRed;
    leds[2][6] = CRGB::OrangeRed;
    leds[2][5] = CRGB::OrangeRed;
    leds[2][4] = CRGB::Orange;
    leds[2][3] = CRGB::Orange;
    leds[2][2] = CRGB::Orange;
    leds[2][1] = CRGB::Yellow;
    leds[2][0] = CRGB::Yellow;
}
    
void loop () {
      scrolldown();
      FastLED.show();
      delay (30);
}

