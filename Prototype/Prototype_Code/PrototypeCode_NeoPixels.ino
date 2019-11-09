#include <FastLED.h>

// Pin Assignments
#define NumLEDS 8
#define DataPin 7
// Pots
#define pot1Pin 1
#define pot2Pin 2
#define pot3Pin 3
#define pot4Pin 4
#define pot5Pin 5
#define pot6Pin 6
#define pot7Pin 7
#define pot8Pin 8


// Color Assignments
#define C0 Black
#define C1 Red
#define C2 Green
#define C3 Blue
#define C4 Yellow
#define C5 Purple
#define C6 Orange
#define C7 Aqua
#define C8 White


// Array Assignments
CRGB leds[NumLEDS];

void setup() { 
      FastLED.addLeds<NEOPIXEL, DataPin>(leds, NumLEDS);
      Serial.begin(9600);
}

void loop() { 
  int pot1 = analogRead(pot1Pin);
  int pot2 = analogRead(pot2Pin);
  int pot3 = analogRead(pot3Pin);
  int pot4 = analogRead(pot4Pin);
  int pot5 = analogRead(pot5Pin);
  int pot6 = analogRead(pot6Pin);
  int pot7 = analogRead(pot7Pin);
  int pot8 = analogRead(pot8Pin);
  
  // Monitor the value of potentiometer 1
  Serial.println(pot1);
  
  //Add red LEDS. stage 1
  if (pot1 > 0 && pot1 < 255)
  { 
    for (int i = 0; i < 2; i++)
    {
      leds[i] = CRGB::C1;
      leds[i+2] = CRGB::C0;
      leds[i+4] = CRGB::C0;
      leds[i+6] = CRGB::C0;
    }
    FastLED.show();
  }
  
  // Add green LEDS. stage 2
  if (pot1 > 255 && pot1 < 511)
  {
    for (int i = 0; i < 2; i++)
    {
      leds[i] = CRGB::C1;
      leds[i+2] = CRGB::C2;
      leds[i+4] = CRGB::C0;
      leds[i+6] = CRGB::C0;
    }
    FastLED.show();
  }
  
  // Add blue LEDS. stage 3
  else if (pot1 > 511 && pot1 < 767)
  {
    for (int i = 0; i < 2; i++)
    {
      leds[i] = CRGB::C1;
      leds[i+2] = CRGB::C2;
      leds[i+4] = CRGB::C3;
      leds[i+6] = CRGB::C0;
    }
    FastLED.show();
  }
  
  //Add white LEDS. stage 4
  else if (pot1 > 767 && pot1 < 1023)
  {
    for (int i = 0; i < 2; i++)
    {
      leds[i] = CRGB::C1;
      leds[i+2] = CRGB::C2;
      leds[i+4] = CRGB::C3;
      leds[i+6] = CRGB::C4;
    }
    FastLED.show();
  }
  
  // LEDS Off
  else
  {
    for (int j = 0; j < NumLEDS; j++)
      leds[j] = CRGB::C0;
    FastLED.show();
  }
}
