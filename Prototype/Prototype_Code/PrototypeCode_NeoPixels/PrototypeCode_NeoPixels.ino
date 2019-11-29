//This program will route sound via a mic and send it to NEOPIXELS

#include <FastLED.h>

// Pin Assignments
#define NumLEDS 64
#define DataPin 12

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
    /*
       THIS IS OLD CODE

    // Reading in from the 8 band pass filters
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
    //Serial.println(pot8);
     */

    /*   Serial.print(" Value 1: ");Serial.print(pot1);Serial.print(" Value 2: ");Serial.print(pot2);Serial.print(" Value 3: ");Serial.print(pot3);Serial.print(" Value 4: ");Serial.print(pot4);
         Serial.print(" Value 5: ");Serial.print(pot5);Serial.print(" Value 6: ");Serial.print(pot6);Serial.print(" Value 7: ");Serial.print(pot7);Serial.print(" Value 8: ");Serial.println(pot8);
     */
    for (i = 1; i < 9; i++)
    {
        // Sets the number of LEDS for the volume level
        switch (i)
        {
            case(1):
                pot1 = getSample();
                setLEDcolor(1, pot1);
            case(2):
                pot2 = getSample();
                setLEDcolor(2, pot2);
            case(3):
                pot3 = getSample();
                setLEDcolor(3, pot3);
            case(4):
                pot4 = getSample();
                setLEDcolor(4, pot4);
            case(5):
                pot5 = getSample():
                setLEDcolor(5, pot5);
            case(6):
                pot6 = getSample();
                setLEDcolor(6, pot6);
            case(7):
                pot7 = getSample();
                setLEDcolor(7, pot7);
            case(8):
                pot8 = getSample();
                setLEDcolor(8, pot8);
        }

                // Turns all LEDS Off if there is "no signal"
                for (int j = 0; j < NumLEDS; j++)
                    leds[j] = CRGB::C0;
                FastLED.show();
    }
}

void getSample()
{
    // Will comunicate (notsure how) with the filter chip to get the value of each filter

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

    FastLED.setBrightness(63);
    // Volume stage 1
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

        FastLED.show();
    }

    // Volume stage 2
    if (pot > 255 && pot < 381)
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
        FastLED.show();
    }

    // Volume stage 3
    else if (pot > 381 && pot < 508)
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
        FastLED.show();
    }

    // Volume stage 4
    else if (pot > 508 && pot < 635)
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
        FastLED.show();
    }


    // Volume stage 5
    else if (pot > 635 && pot < 762)
    {
        switch (pixelNum)
        {
            case 1:
                leds[row1] = CRGB::C1;
                leds[row2] = CRGB::C1;
                leds[row3] = CRGB::C1;
                leds[row4] = CRGB::C1;
                leds[row5] = CRGB::C1;
                break;      
            case 2:
                leds[row1] = CRGB::C2;
                leds[row2] = CRGB::C2;
                leds[row3] = CRGB::C2;
                leds[row4] = CRGB::C2;
                leds[row5] = CRGB::C2;
                break; 
            case 3:
                leds[row1] = CRGB::C3;
                leds[row2] = CRGB::C3;
                leds[row3] = CRGB::C3;
                leds[row4] = CRGB::C3;
                leds[row5] = CRGB::C3;
                break;
            case 4:
                leds[row1] = CRGB::C4;
                leds[row2] = CRGB::C4;
                leds[row3] = CRGB::C4;
                leds[row4] = CRGB::C4;
                leds[row5] = CRGB::C4;
                break;
            case 5:
                leds[row1] = CRGB::C5;
                leds[row2] = CRGB::C5;
                leds[row3] = CRGB::C5;
                leds[row4] = CRGB::C5;
                leds[row5] = CRGB::C5;
                break;
            case 6:
                leds[row1] = CRGB::C6;
                leds[row2] = CRGB::C6;
                leds[row3] = CRGB::C6;
                leds[row4] = CRGB::C6;
                leds[row5] = CRGB::C6;
                break;
            case 7:
                leds[row1] = CRGB::C7;
                leds[row2] = CRGB::C7;
                leds[row3] = CRGB::C7;
                leds[row4] = CRGB::C7;
                leds[row5] = CRGB::C7;
                break;
            case 8:
                leds[row1] = CRGB::C8;
                leds[row2] = CRGB::C8;
                leds[row3] = CRGB::C8;
                leds[row4] = CRGB::C8;
                leds[row5] = CRGB::C8;
                break;
        }
        FastLED.show();
    }


    // Volume stage 6
    else if (pot > 762 && pot < 889)
    {
        switch (pixelNum)
        {
            case 1:
                leds[row1] = CRGB::C1;
                leds[row2] = CRGB::C1;
                leds[row3] = CRGB::C1;
                leds[row4] = CRGB::C1;
                leds[row5] = CRGB::C1;
                leds[row6] = CRGB::C1;
                break;      
            case 2:
                leds[row1] = CRGB::C2;
                leds[row2] = CRGB::C2;
                leds[row3] = CRGB::C2;
                leds[row4] = CRGB::C2;
                leds[row5] = CRGB::C2;
                leds[row6] = CRGB::C2;
                break; 
            case 3:
                leds[row1] = CRGB::C3;
                leds[row2] = CRGB::C3;
                leds[row3] = CRGB::C3;
                leds[row4] = CRGB::C3;
                leds[row5] = CRGB::C3;
                leds[row6] = CRGB::C3;
                break;
            case 4:
                leds[row1] = CRGB::C4;
                leds[row2] = CRGB::C4;
                leds[row3] = CRGB::C4;
                leds[row4] = CRGB::C4;
                leds[row5] = CRGB::C4;
                leds[row6] = CRGB::C4;
                break;
            case 5:
                leds[row1] = CRGB::C5;
                leds[row2] = CRGB::C5;
                leds[row3] = CRGB::C5;
                leds[row4] = CRGB::C5;
                leds[row5] = CRGB::C5;
                leds[row6] = CRGB::C5;
                break;
            case 6:
                leds[row1] = CRGB::C6;
                leds[row2] = CRGB::C6;
                leds[row3] = CRGB::C6;
                leds[row4] = CRGB::C6;
                leds[row5] = CRGB::C6;
                leds[row6] = CRGB::C6;
                break;
            case 7:
                leds[row1] = CRGB::C7;
                leds[row2] = CRGB::C7;
                leds[row3] = CRGB::C7;
                leds[row4] = CRGB::C7;
                leds[row5] = CRGB::C7;
                leds[row6] = CRGB::C7;
                break;
            case 8:
                leds[row1] = CRGB::C8;
                leds[row2] = CRGB::C8;
                leds[row3] = CRGB::C8;
                leds[row4] = CRGB::C8;
                leds[row5] = CRGB::C8;
                leds[row6] = CRGB::C8;
                break;
        }
        FastLED.show();
    }
    // Volume stage 7
    else if (pot > 889 && pot < 1000)
    {
        switch (pixelNum)
        {
            case 1:
                leds[row1] = CRGB::C1;
                leds[row2] = CRGB::C1;
                leds[row3] = CRGB::C1;
                leds[row4] = CRGB::C1;
                leds[row5] = CRGB::C1;
                leds[row6] = CRGB::C1;
                leds[row7] = CRGB::C1;
                break;      
            case 2:
                leds[row1] = CRGB::C2;
                leds[row2] = CRGB::C2;
                leds[row3] = CRGB::C2;
                leds[row4] = CRGB::C2;
                leds[row5] = CRGB::C2;
                leds[row6] = CRGB::C2;
                leds[row7] = CRGB::C2;
                break; 
            case 3:
                leds[row1] = CRGB::C3;
                leds[row2] = CRGB::C3;
                leds[row3] = CRGB::C3;
                leds[row4] = CRGB::C3;
                leds[row5] = CRGB::C3;
                leds[row6] = CRGB::C3;
                leds[row7] = CRGB::C3;
                break;
            case 4:
                leds[row1] = CRGB::C4;
                leds[row2] = CRGB::C4;
                leds[row3] = CRGB::C4;
                leds[row4] = CRGB::C4;
                leds[row5] = CRGB::C4;
                leds[row6] = CRGB::C4;
                leds[row7] = CRGB::C4;
                break;
            case 5:
                leds[row1] = CRGB::C5;
                leds[row2] = CRGB::C5;
                leds[row3] = CRGB::C5;
                leds[row4] = CRGB::C5;
                leds[row5] = CRGB::C5;
                leds[row6] = CRGB::C5;
                leds[row7] = CRGB::C5;
                break;
            case 6:
                leds[row1] = CRGB::C6;
                leds[row2] = CRGB::C6;
                leds[row3] = CRGB::C6;
                leds[row4] = CRGB::C6;
                leds[row5] = CRGB::C6;
                leds[row6] = CRGB::C6;
                leds[row7] = CRGB::C6;
                break;
            case 7:
                leds[row1] = CRGB::C7;
                leds[row2] = CRGB::C7;
                leds[row3] = CRGB::C7;
                leds[row4] = CRGB::C7;
                leds[row5] = CRGB::C7;
                leds[row6] = CRGB::C7;
                leds[row7] = CRGB::C7;
                break;
            case 8:
                leds[row1] = CRGB::C8;
                leds[row2] = CRGB::C8;
                leds[row3] = CRGB::C8;
                leds[row4] = CRGB::C8;
                leds[row5] = CRGB::C8;
                leds[row6] = CRGB::C8;
                leds[row7] = CRGB::C8;
                break;
        }
        FastLED.show();
    }

    // Volume stage 8
    else if (pot > 1000 && pot < 1024)
    {
        switch (pixelNum)
        {
            case 1:
                leds[row1] = CRGB::C1;
                leds[row2] = CRGB::C1;
                leds[row3] = CRGB::C1;
                leds[row4] = CRGB::C1;
                leds[row5] = CRGB::C1;
                leds[row6] = CRGB::C1;
                leds[row7] = CRGB::C1;
                leds[row8] = CRGB::C1;
                break;      
            case 2:
                leds[row1] = CRGB::C2;
                leds[row2] = CRGB::C2;
                leds[row3] = CRGB::C2;
                leds[row4] = CRGB::C2;
                leds[row5] = CRGB::C2;
                leds[row6] = CRGB::C2;
                leds[row7] = CRGB::C2;
                leds[row8] = CRGB::C2;
                break; 
            case 3:
                leds[row1] = CRGB::C3;
                leds[row2] = CRGB::C3;
                leds[row3] = CRGB::C3;
                leds[row4] = CRGB::C3;
                leds[row5] = CRGB::C3;
                leds[row6] = CRGB::C3;
                leds[row7] = CRGB::C3;
                leds[row8] = CRGB::C3;
                break;
            case 4:
                leds[row1] = CRGB::C4;
                leds[row2] = CRGB::C4;
                leds[row3] = CRGB::C4;
                leds[row4] = CRGB::C4;
                leds[row5] = CRGB::C4;
                leds[row6] = CRGB::C4;
                leds[row7] = CRGB::C4;
                leds[row8] = CRGB::C4;
                break;
            case 5:
                leds[row1] = CRGB::C5;
                leds[row2] = CRGB::C5;
                leds[row3] = CRGB::C5;
                leds[row4] = CRGB::C5;
                leds[row5] = CRGB::C5;
                leds[row6] = CRGB::C5;
                leds[row7] = CRGB::C5;
                leds[row8] = CRGB::C5;
                break;
            case 6:
                leds[row1] = CRGB::C6;
                leds[row2] = CRGB::C6;
                leds[row3] = CRGB::C6;
                leds[row4] = CRGB::C6;
                leds[row5] = CRGB::C6;
                leds[row6] = CRGB::C6;
                leds[row7] = CRGB::C6;
                leds[row8] = CRGB::C6;
                break;
            case 7:
                leds[row1] = CRGB::C7;
                leds[row2] = CRGB::C7;
                leds[row3] = CRGB::C7;
                leds[row4] = CRGB::C7;
                leds[row5] = CRGB::C7;
                leds[row6] = CRGB::C7;
                leds[row7] = CRGB::C7;
                leds[row8] = CRGB::C7;
                break;
            case 8:
                leds[row1] = CRGB::C8;
                leds[row2] = CRGB::C8;
                leds[row3] = CRGB::C8;
                leds[row4] = CRGB::C8;
                leds[row5] = CRGB::C8;
                leds[row6] = CRGB::C8;
                leds[row7] = CRGB::C8;
                leds[row8] = CRGB::C8;
                break;
        }
        FastLED.show();
    }
}


// Likely to delete cuz its buggin
void rowMultiplier(int multi)
{
    for (int i = 0; i < multi; i++)
    {
        String R = "row";
        R.concat(i);
        //        leds[R] = CRGB::C1;
    }
}
