//This program will route sound to NEOPIXELS

#include <FastLED.h>

// Pin Assignments
#define NumLEDS 8
#define DataPin 7
// Pots
#define pot1Pin 0
#define pot2Pin 1
#define pot3Pin 2
#define pot4Pin 3
#define pot5Pin 4
#define pot6Pin 5
#define pot7Pin 6
#define pot8Pin 7


// Color Assignments
#define C0 Black
#define C1 Red
#define C2 Green
#define C3 Blue
#define C4 Yellow
#define C5 Purple
#define C6 White
#define C7 Aqua
//#define C8 // pick new color White


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
  
  // Monitor the value of all potentiometers
 /* 
  Serial.print(" Value 1: ");Serial.print(pot1);Serial.print(" Value 2: ");Serial.print(pot2);Serial.print(" Value 3: ");Serial.print(pot3);Serial.print(" Value 4: ");Serial.print(pot4);
  Serial.print(" Value 5: ");Serial.print(pot5);Serial.print(" Value 6: ");Serial.print(pot6);Serial.print(" Value 7: ");Serial.print(pot7);Serial.print(" Value 8: ");Serial.println(pot8);
*/
  int i;
/// LEDS 1 /// LEDS 1 /// LEDS 1 /// LEDS 1 /// LEDS 1 /// LEDS 1 /// LEDS 1 /// LEDS 1 /// LEDS 1 /// LEDS 1 /// LEDS 1 /// LEDS 1 /// LEDS 1 ///
  //Add red LEDS. stage 1
 for (i=1; i<2; i++)
 {
  if (pot1 >15 && pot1 < 255)
  {
    leds[i-1] = CRGB::C1;
    FastLED.setBrightness(63);
    FastLED.show();
  }
  
  // Add green LEDS. stage 2
  if (pot1 > 255 && pot1 < 511)
  {
    leds[i-1] = CRGB::C1;
    FastLED.setBrightness(100);
    FastLED.show();
  }
  
  // Add blue LEDS. stage 3
  else if (pot1 > 511 && pot1 < 767)
  {
    leds[i-1] = CRGB::C1;
    FastLED.setBrightness(170);
    FastLED.show();
  }
  
  //Add white LEDS. stage 4
  else if (pot1 > 767 && pot1 < 1024)
  {
    leds[i-1] = CRGB::C1;
    FastLED.setBrightness(255);
    FastLED.show();
  }
}

/// LEDS 2 /// LEDS 2 /// LEDS 2 /// LEDS 2 /// LEDS 2 /// LEDS 2 /// LEDS 2 /// LEDS 2 /// LEDS 2 /// LEDS 2 /// LEDS 2 /// LEDS 2 /// LEDS 2 ///
  //Add red LEDS. stage 1
  for (i=2; i<3; i++)
 {
  if (pot2 >15 && pot2 < 255)
  {
    leds[i-1] = CRGB::C2;
    FastLED.setBrightness(63);
    FastLED.show();
  }
  
  // Add green LEDS. stage 2
  if (pot2 > 255 && pot2 < 511)
  {
    leds[i-1] = CRGB::C2;
    FastLED.setBrightness(100);
    FastLED.show();
  }
  
  // Add blue LEDS. stage 3
  else if (pot2 > 511 && pot2 < 767)
  {
    leds[i-1] = CRGB::C2;
    FastLED.setBrightness(170);
    FastLED.show();
  }
  
  //Add white LEDS. stage 4
  else if (pot2 > 767 && pot2 < 1024)
  {
    leds[i-1] = CRGB::C2;
    FastLED.setBrightness(255);
    FastLED.show();
  }
 }

/// LEDS 3 /// LEDS 3 /// LEDS 3 /// LEDS 3 /// LEDS 3 /// LEDS 3 /// LEDS 3 /// LEDS 3 /// LEDS 3 /// LEDS 3 /// LEDS 3 /// LEDS 3 /// LEDS 3 ///
  //Add red LEDS. stage 1
   for (i=3; i<4; i++)
 {
  if (pot3 >15 && pot3 < 255)
  {
    leds[i-1] = CRGB::C3;
    FastLED.setBrightness(63);
    FastLED.show();
  }
  
  // Add green LEDS. stage 2
  if (pot3 > 255 && pot3 < 511)
  {
    leds[i-1] = CRGB::C3;
    FastLED.setBrightness(100);
    FastLED.show();
  }
  
  // Add blue LEDS. stage 3
  else if (pot3 > 511 && pot3 < 767)
  {
    leds[i-1] = CRGB::C3;
    FastLED.setBrightness(170);
    FastLED.show();
  }
  
  //Add white LEDS. stage 4
  else if (pot3 > 767 && pot3 < 1024)
  {
    leds[i-1] = CRGB::C3;
    FastLED.setBrightness(255);
    FastLED.show();
  }
 }
/// LEDS 4 /// LEDS 4 /// LEDS 4 /// LEDS 4 /// LEDS 4 /// LEDS 4 /// LEDS 4 /// LEDS 4 /// LEDS 4 /// LEDS 4 /// LEDS 4 /// LEDS 4 /// LEDS 4 ///
  //Add red LEDS. stage 1
  for (i=4;i<5;i++)
  {
    if (pot4 >15 && pot4 < 255)
  {
    leds[i-1] = CRGB::C4;
    FastLED.setBrightness(63);
    FastLED.show();
  }
  
  // Add green LEDS. stage 2
  if (pot4 > 255 && pot4 < 511)
  {
    leds[i-1] = CRGB::C4;
    FastLED.setBrightness(100);
    FastLED.show();
  }
  
  // Add blue LEDS. stage 3
  else if (pot4 > 511 && pot4 < 767)
  {
    leds[i-1] = CRGB::C4;
    FastLED.setBrightness(170);
    FastLED.show();
  }
  
  //Add white LEDS. stage 4
  else if (pot4 > 767 && pot4 < 1024)
  {
    leds[i-1] = CRGB::C4;
    FastLED.setBrightness(255);
    FastLED.show();
  }
 }
/// LEDS 5 /// LEDS 5 /// LEDS 5 /// LEDS 5 /// LEDS 5 /// LEDS 5 /// LEDS 5 /// LEDS 5 /// LEDS 5 /// LEDS 5 /// LEDS 5 /// LEDS 5 /// LEDS 5 ///
  //Add red LEDS. stage 1
   for (i=5; i<6; i++)
 {
  if (pot5 >15 && pot5 < 255)
  {
    leds[i-1] = CRGB::C5;
    FastLED.setBrightness(63);
    FastLED.show();
  }
  
  // Add green LEDS. stage 2
  if (pot5 > 255 && pot5 < 511)
  {
    leds[i-1] = CRGB::C5;
    FastLED.setBrightness(100);
    FastLED.show();
  }
  
  // Add blue LEDS. stage 3
  else if (pot5 > 511 && pot5 < 767)
  {
    leds[i-1] = CRGB::C5;
    FastLED.setBrightness(170);
    FastLED.show();
  }
  
  //Add white LEDS. stage 4
  else if (pot5 > 767 && pot5 < 1024)
  {
    leds[i-1] = CRGB::C5;
    FastLED.setBrightness(255);
    FastLED.show();
  }
 }
 
/// LEDS 6 /// LEDS 6 /// LEDS 6 /// LEDS 6 /// LEDS 6 /// LEDS 6 /// LEDS 6 /// LEDS 6 /// LEDS 6 /// LEDS 6 /// LEDS 6 /// LEDS 6 /// LEDS 6 ///
  //Add red LEDS. stage 1
   for (i=6; i<7; i++)
 {
  if (pot6 >15 && pot6 < 255)
  {
    leds[i-1] = CRGB::C6;
    FastLED.setBrightness(63);
    FastLED.show();
  }
  
  // Add green LEDS. stage 2
  if (pot6 > 255 && pot6 < 511)
  {
    leds[i-1] = CRGB::C6;
    FastLED.setBrightness(100);
    FastLED.show();
  }
  
  // Add blue LEDS. stage 3
  else if (pot6 > 511 && pot6 < 767)
  {
    leds[i-1] = CRGB::C6;
    FastLED.setBrightness(170);
    FastLED.show();
  }
  
  //Add white LEDS. stage 4
  else if (pot6 > 767 && pot6 < 1024)
  {
    leds[i-1] = CRGB::C6;
    FastLED.setBrightness(255);
    FastLED.show();
  }
 }
 /*

/// LEDS 7 /// LEDS 7 /// LEDS 7 /// LEDS 7 /// LEDS 7 /// LEDS 7 /// LEDS 7 /// LEDS 7 /// LEDS 7 /// LEDS 7 /// LEDS 7 /// LEDS 7 /// LEDS 7 ///
  //Add red LEDS. stage 1
   for (i=7; i<8; i++)
 {
  if (pot7 >15 && pot7 < 255)

  {
    leds[i-1] = CRGB::C7;
    FastLED.setBrightness(63);
    FastLED.show();
  }
  
  // Add green LEDS. stage 2
  if (pot7 > 255 && pot7 < 511)
  {
    leds[i-1] = CRGB::C7;
    FastLED.setBrightness(100);
    FastLED.show();
  }
  
  // Add blue LEDS. stage 3
  else if (pot7 > 511 && pot7 < 767)
  {
    leds[i-1] = CRGB::C7;
    FastLED.setBrightness(170);
    FastLED.show();
  }
  
  //Add white LEDS. stage 4
  else if (pot7 > 767 && pot7 < 1024)
  {
    leds[i-1] = CRGB::C7;
    FastLED.setBrightness(255);
    FastLED.show();
  }
 }
/// LEDS 8 /// LEDS 8 /// LEDS 8 /// LEDS 8 /// LEDS 8 /// LEDS 8 /// LEDS 8 /// LEDS 8 /// LEDS 8 /// LEDS 8 /// LEDS 8 /// LEDS 8 /// LEDS 8 ///
  //Add red LEDS. stage 1
   for (i=8; i<9; i++)
 {
  if (pot8 >15 && pot8 < 255)
  {
    leds[i-1] = CRGB::C8;
    FastLED.setBrightness(63);
    FastLED.show();
  }
  
  // Add green LEDS. stage 2
  if (pot8 > 255 && pot8 < 511)
  {
    leds[i-1] = CRGB::C8;
    FastLED.setBrightness(100);
    FastLED.show();
  }
  
  // Add blue LEDS. stage 3
  else if (pot8 > 511 && pot8 < 767)
  {
    leds[i-1] = CRGB::C8;
    FastLED.setBrightness(170);
    FastLED.show();
  }
  
  //Add white LEDS. stage 4
  else if (pot8 > 767 && pot8 < 1024)
  {
    leds[i-1] = CRGB::C8;
    FastLED.setBrightness(255);
    FastLED.show();
  }
 }
*/
  // LEDS Off
  
    for (int j = 0; j < NumLEDS; j++)
      leds[j] = CRGB::C0;
    FastLED.show();
  }
