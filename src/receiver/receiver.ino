#include <FastLED.h>


#define DATA_PIN A0
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 72

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(100);
  Serial.begin(9600);
}

void loop() {
  // Вращение светодиодами синего цвета
  for (int cnt=0; cnt < 5; cnt++){
    for (int i = 1; i < NUM_LEDS - 2; i++) {
      fill_solid(leds, NUM_LEDS, CRGB::White);
      leds[i-1] = CRGB::BLUE;  // Оставим один светодиод белым для визуализации вращения
      leds[i] = CRGB::White;
      leds[i+1] = CRGB::White;
      FastLED.show();
      delay(50);
      FastLED.clear();
    }
  }

  // Мигание зеленым цветом три раза
  for (int j = 0; j < 5; j++) {
    fill_solid(leds, NUM_LEDS, CRGB::Red);
    FastLED.show();
    delay(500);
    FastLED.clear();
    FastLED.show();
    delay(500);
    FastLED.clear();
  }

  // Горение красным цветом
  // fill_solid(leds, NUM_LEDS, CRGB::Green);
  // FastLED.show();
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  delay(10000);
}
