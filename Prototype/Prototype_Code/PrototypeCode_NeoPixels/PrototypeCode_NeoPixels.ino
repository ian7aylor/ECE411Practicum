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
#define C8 Orange // pick new color White


// Array Assignments
CRGB leds[NumLEDS];


// Setup for the pixels
void setup() 
{ 
	FastLED.addLeds<NEOPIXEL, DataPin>(leds, NumLEDS);
	Serial.begin(57600);
}

// This will loop for all of time
void loop() 
{
	int pot1 = analogRead(pot1Pin);
	int pot2 = analogRead(pot2Pin);
	int pot3 = analogRead(pot3Pin);
	int pot4 = analogRead(pot4Pin);
	int pot5 = analogRead(pot5Pin);
	int pot6 = analogRead(pot6Pin);
	int pot7 = analogRead(pot7Pin);
	int pot8 = analogRead(pot8Pin);

	// Monitor the value of all potentiometers
  char printer[99];	
	sprintf(printer, "Value 1: %d  Value2: %d  Value3: %d  Value4: %d  Value5: %d  Value6: %d  Value7: %d  Value8: %d", pot1, pot2, pot3, pot4, pot5, pot6, pot7, pot8);
  Serial.println(printer);

	/*   Serial.print(" Value 1: ");Serial.print(pot1);Serial.print(" Value 2: ");Serial.print(pot2);Serial.print(" Value 3: ");Serial.print(pot3);Serial.print(" Value 4: ");Serial.print(pot4);
	   Serial.print(" Value 5: ");Serial.print(pot5);Serial.print(" Value 6: ");Serial.print(pot6);Serial.print(" Value 7: ");Serial.print(pot7);Serial.print(" Value 8: ");Serial.println(pot8);
	 */
	setLEDcolor(1, pot1);
	setLEDcolor(2, pot2);
	setLEDcolor(3, pot3);
	setLEDcolor(4, pot4);
	setLEDcolor(5, pot5);
	setLEDcolor(6, pot6);
	//setLEDcolor(7, pot7);
	//setLEDcolor(8, pot8);

		// LEDS Off  
		for (int j = 0; j < NumLEDS; j++)
			leds[j] = CRGB::C0;
	FastLED.show();

}

void setLEDcolor(int pixelNum, int pot)
{
    // Set the values for the pixels for each row
    int row1 = pixelNum-1 + (8 * 0);
    int row2 = pixelNum-1 + (8 * 1);
    int row3 = pixelNum-1 + (8 * 2);
    int row4 = pixelNum-1 + (8 * 3);
    int row5 = pixelNum-1 + (8 * 4);
    int row6 = pixelNum-1 + (8 * 5);
    int row7 = pixelNum-1 + (8 * 6);
    int row8 = pixelNum-1 + (8 * 7);

  if (pot >15 && pot < 255)
	{
    switch (pixelNum)
   {
      case 1:
        leds[row1] = CRGB::C1;
      break;      
      case 2:
        leds[row1] = CRGB::C2;
      break; 
       case 3:
        leds[row1] = CRGB::C3;
      break;
       case 4:
        leds[row1] = CRGB::C4;
      break;
       case 5:
        leds[row1] = CRGB::C5;
      break;
       case 6:
        leds[row1] = CRGB::C6;
      break;
      case 7:
        leds[row1] = CRGB::C7;
      break;
       case 8:
        leds[row1] = CRGB::C8;
      break;
   }
		FastLED.setBrightness(63);
		FastLED.show();
	}

	// stage 2
	if (pot > 255 && pot < 511)
	{
		 switch (pixelNum)
   {
        case 1:
        leds[row1] = CRGB::C1;
		leds[row2] = CRGB::C1;
      break;      
      case 2:
        leds[row1] = CRGB::C2;
		leds[row2] = CRGB::C2;
      break; 
       case 3:
        leds[row1] = CRGB::C3;
		leds[row2] = CRGB::C3;
      break;
       case 4:
        leds[row1] = CRGB::C4;
		leds[row2] = CRGB::C4;
      break;
       case 5:
        leds[row1] = CRGB::C5;
		leds[row2] = CRGB::C5;
      break;
       case 6:
        leds[row1] = CRGB::C6;
		leds[row2] = CRGB::C6;
      break;
      case 7:
        leds[row1] = CRGB::C7;
		leds[row2] = CRGB::C7;
      break;
       case 8:
        leds[row1] = CRGB::C8;
		leds[row2] = CRGB::C8;
      break;
   }
		FastLED.setBrightness(100);
		FastLED.show();
	}

	// stage 3
	else if (pot > 511 && pot < 767)
	{
		 switch (pixelNum)
   {
        case 1:
        leds[row1] = CRGB::C1;
		leds[row2] = CRGB::C1;
		leds[row3] = CRGB::C1;
      break;      
      case 2:
        leds[row1] = CRGB::C2;
		leds[row2] = CRGB::C2;
		leds[row3] = CRGB::C2;
      break; 
       case 3:
        leds[row1] = CRGB::C3;
		leds[row2] = CRGB::C3;
		leds[row3] = CRGB::C3;
      break;
       case 4:
        leds[row1] = CRGB::C4;
		leds[row2] = CRGB::C4;
		leds[row3] = CRGB::C4;
      break;
       case 5:
        leds[row1] = CRGB::C5;
		leds[row2] = CRGB::C5;
		leds[row3] = CRGB::C5;
      break;
       case 6:
        leds[row1] = CRGB::C6;
		leds[row2] = CRGB::C6;
		leds[row3] = CRGB::C6;
      break;
      case 7:
        leds[row1] = CRGB::C7;
		leds[row2] = CRGB::C7;
		leds[row3] = CRGB::C7;
      break;
       case 8:
        leds[row1] = CRGB::C8;
		leds[row2] = CRGB::C8;
		leds[row3] = CRGB::C8;
      break;
   }
		FastLED.setBrightness(170);
		FastLED.show();
	}

	// stage 4
	else if (pot > 767 && pot < 1024)
	{
		 switch (pixelNum)
   {
      case 1:
        leds[row1] = CRGB::C1;
		leds[row2] = CRGB::C1;
		leds[row3] = CRGB::C1;
		leds[row4] = CRGB::C1;
      break;      
      case 2:
        leds[row1] = CRGB::C2;
		leds[row2] = CRGB::C2;
		leds[row3] = CRGB::C2;
		leds[row4] = CRGB::C2;
      break; 
       case 3:
        leds[row1] = CRGB::C3;
		leds[row2] = CRGB::C3;
		leds[row3] = CRGB::C3;
		leds[row4] = CRGB::C3;
      break;
       case 4:
        leds[row1] = CRGB::C4;
		leds[row2] = CRGB::C4;
		leds[row3] = CRGB::C4;
		leds[row4] = CRGB::C4;
      break;
       case 5:
        leds[row1] = CRGB::C5;
		leds[row2] = CRGB::C5;
		leds[row3] = CRGB::C5;
		leds[row4] = CRGB::C5;
      break;
       case 6:
        leds[row1] = CRGB::C6;
		leds[row2] = CRGB::C6;
		leds[row3] = CRGB::C6;
		leds[row4] = CRGB::C6;
      break;
      case 7:
        leds[row1] = CRGB::C7;
		leds[row2] = CRGB::C7;
		leds[row3] = CRGB::C7;
		leds[row4] = CRGB::C7;
      break;
       case 8:
        leds[row1] = CRGB::C8;
		leds[row2] = CRGB::C8;
		leds[row3] = CRGB::C8;
		leds[row4] = CRGB::C8;
      break;
   }
		FastLED.setBrightness(255);
		FastLED.show();
	}
}
