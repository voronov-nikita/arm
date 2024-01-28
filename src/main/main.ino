#define NUM_LEDS 72
#include "FastLED.h"
#define PIN 6

CRGB leds[NUM_LEDS];
byte counter;


void setup() {
  Serial.begin(9600);
  
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(50);
  pinMode(13, OUTPUT);
}
void loop() {
  int num = Serial.parseInt();
  Serial.println(num);
  // for (int i = 0; i < NUM_LEDS; i++ ) {         // от 0 до первой трети
  //   leds[i] = CHSV(counter + i * 2, 255, 255);  // HSV. Увеличивать HUE (цвет)
  //   // умножение i уменьшает шаг радуги
  // }
  for (int i; i<NUM_LEDS; i++) leds[i] = CHSV(650, 255, 255);
  counter++;        // counter меняется от 0 до 255 (тип данных byte)
  FastLED.show();
  delay(1);         // скорость движения радуги
}