#include <FastLED.h>

// Pin Assignments
#define NumLEDS 8
#define DataPin 7
#define pot1Pin 2

// Color Assignments
#define C0 Black
#define C1 Red
#define C2 Green
#define C3 Blue
#define C4 White

// Array Assignments
CRGB leds[NumLEDS];

void setup() { 
      FastLED.addLeds<NEOPIXEL, DataPin>(leds, NumLEDS);
      Serial.begin(9600);
}

void loop() { 
  int pot1 = analogRead(pot1Pin);
  
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
