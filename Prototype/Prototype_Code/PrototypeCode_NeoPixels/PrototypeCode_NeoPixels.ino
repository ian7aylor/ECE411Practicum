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
	//int pot7 = analogRead(pot7Pin);
	//int pot8 = analogRead(pot8Pin);

	// Monitor the value of all potentiometers
	/* 
	   Serial.print(" Value 1: ");Serial.print(pot1);Serial.print(" Value 2: ");Serial.print(pot2);Serial.print(" Value 3: ");Serial.print(pot3);Serial.print(" Value 4: ");Serial.print(pot4);
	   Serial.print(" Value 5: ");Serial.print(pot5);Serial.print(" Value 6: ");Serial.print(pot6);Serial.print(" Value 7: ");Serial.print(pot7);Serial.print(" Value 8: ");Serial.println(pot8);
	 */

	setLEDcolor(1, pot1, char(CRGB::C1));
	setLEDcolor(2, pot2, char(CRGB::C2));
	setLEDcolor(3, pot3, char(CRGB::C3));
	setLEDcolor(4, pot4, char(CRGB::C4));
	setLEDcolor(5, pot5, char(CRGB::C5));
	setLEDcolor(6, pot6, char(CRGB::C6));
//	setLEDcolor(7, pot7, char(CRGB::C7));
//	setLEDcolor(8, pot8, char(CRGB::C8));

		// LEDS Off  
		for (int j = 0; j < NumLEDS; j++)
			leds[j] = CRGB::C0;
	FastLED.show();

}

void setLEDcolor(int pixelNum, int pot, char color)
{
	if (pot >15 && pot < 255)
	{
		leds[pixelNum] = color;
		FastLED.setBrightness(63);
		FastLED.show();
	}

	// stage 2
	if (pot > 255 && pot < 511)
	{
		leds[pixelNum] = color;
		FastLED.setBrightness(100);
		FastLED.show();
	}

	// stage 3
	else if (pot > 511 && pot < 767)
	{
		leds[pixelNum] = color;
		FastLED.setBrightness(170);
		FastLED.show();
	}

	// stage 4
	else if (pot > 767 && pot < 1024)
	{
		leds[pixelNum] = color;
		FastLED.setBrightness(255);
		FastLED.show();
	}
}
