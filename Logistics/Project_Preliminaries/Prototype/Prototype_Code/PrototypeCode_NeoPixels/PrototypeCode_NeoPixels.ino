//This program will route sound via a mic and send it to NEOPIXELS

#include <FastLED.h>

// Pin Assignments
#define DataPin 7   // Pin that communicates to LED output strip 
#define RESETPIN 3  // Pin for reset button
#define STROBEPIN 4 // Pin connecting to strobe of the filter chip 
#define CHIP A0     // Connect to the 7 BandPass filter chip 

// Pots
#define pot1Pin 0
#define pot2Pin 1
#define pot3Pin 2
#define pot4Pin 3
#define pot5Pin 4
#define pot6Pin 5
#define pot7Pin 6
#define pot8Pin 7

// Delay Value
#define STRD 3000//0.072  // Delay for strobe cycle
#define VALD 0.036 // Delay for a valid data
#define REMAIN 0.036 // Delay for the remaining time after valid data

// Color Assignments
#define C0 Black  // no input
#define C1 Red    // 1st row of LEDs
#define C2 Green  // 2nd row of LEDs
#define C3 Blue   // 3rd row of LEDs
#define C4 Yellow // 4th row of LEDs
#define C5 Purple // 5th row of LEDs
#define C6 White  // 6th row of LEDs
#define C7 Aqua   // 7th row of LEDs
#define C8 Orange // 8th row of LEDs

// Array Assignments
#define NumLEDS 64
CRGB leds[NumLEDS];

// Setup for the pixels
void setup() 
{ 
    // Brought in from the FastLED Library
    FastLED.addLeds<NEOPIXEL, DataPin>(leds, NumLEDS);
    Serial.begin(57600); // start a serial monitor
    
    /*
    Not needed per Marks comments. No reference ground is needed
    analogReference(INTERNAL); // Sets the AREF to 2.5 for the reference for the filter chip
    analogWrite(IO11,127); // (MAYBE?) Sets the clock signal to the IO11 Pin at 50% duty cycle
    */

    // Sets the Datapin and Reset and Strobe pins as ooutputs
    digitalWrite(DataPin, OUTPUT); 
    digitalWrite(RESETPIN, OUTPUT); 
    digitalWrite(STROBEPIN, OUTPUT);

    // Sets the Chip pin as an input
    analogWrite(CHIP, INPUT);

    // Sending the strobe and reset signals to initialize the filter
    digitalWrite(RESETPIN, HIGH); //reset = 1
    digitalWrite(STROBEPIN, HIGH); //strobe = 1
    delay(STRD);
    digitalWrite(STROBEPIN, LOW); // delay then strobe = 0
    delay(STRD);
    digitalWrite(RESETPIN, LOW); //reset = 0
    digitalWrite(STROBEPIN, HIGH); //reset = 1
    delay(STRD);
}

// This will loop for all of time
void loop() 
{
    digitalWrite(RESETPIN, LOW); //reset = 0
    /*   Serial.print(" Value 1: ");Serial.print(pot1);Serial.print(" Value 2: ");Serial.print(pot2);Serial.print(" Value 3: ");Serial.print(pot3);Serial.print(" Value 4: ");Serial.print(pot4);
         Serial.print(" Value 5: ");Serial.print(pot5);Serial.print(" Value 6: ");Serial.print(pot6);Serial.print(" Value 7: ");Serial.print(pot7);Serial.print(" Value 8: ");Serial.println(pot8);
     */
    for (int i = 1; i < 8; i++)
    {
       digitalWrite(STROBEPIN, LOW); // Strobe = 0
       delay(VALD);
      // Serial.println(strobe);
//       strobe = strobeChip(strobe); // delay then Strobe is HIGH
       int pot1, pot2, pot3, pot4, pot5, pot6, pot7;
    // Monitor the value of all potentiometers
    /* 
     char printer[99];  
    sprintf(printer, "Value 1: %d  Value2: %d  Value3: %d  Value4: %d  Value5: %d  Value6: %d  Value7: %d", pot1, pot2, pot3, pot4, pot5, pot6, pot7);
    Serial.println(printer);
     */       
        // Sets the number of LEDS for the volume level
        switch (i)
        {
            case(1): // 63 Hz
                pot1 = getSample();
                setLEDcolor(1, pot1);
                Serial.print("filter 1: ");
                Serial.println(pot1);
            case(2): // 160 Hz
                pot2 = getSample();
                setLEDcolor(2, pot2);
                Serial.print("filter 2: ");
                Serial.println(pot2);
            case(3): // 400 Hz
                pot3 = getSample();
                setLEDcolor(3, pot3);
                Serial.print("filter 3: ");
                Serial.println(pot3);
            case(4): // 1 kHz
                pot4 = getSample();
                setLEDcolor(4, pot4);
                Serial.print("filter 4: ");
                Serial.println(pot4);
            case(5): // 2.5 kHz
                pot5 = getSample();
                setLEDcolor(5, pot5);
                Serial.print("filter 5: ");
                Serial.println(pot5);
            case(6): //6.25 kHz
                pot6 = getSample();
                setLEDcolor(6, pot6);
                Serial.print("filter 6: ");
                Serial.println(pot6);
            case(7): // 16 kHz
                pot7 = getSample();
                setLEDcolor(7, pot7);
                Serial.print("filter 7: ");
                Serial.println(pot7);
        }
                // Turns all LEDS Off if there is "no signal"
                for (int j = 0; j < NumLEDS; j++)
                    leds[j] = CRGB::C0;
                FastLED.show();
                delay(REMAIN);
                delay(STRD); //delete later
                digitalWrite(STROBEPIN, HIGH); //reset = 1
                delay(STRD);             
    }
}

int getSample()
{
    // Will comunicate (notsure how) with the filter chip to get the value of each filter
    /* Data comes in the following order
        63 Hz
        160 Hz
        400 Hz
        1.0 KHz
        2.5 KHz
        6.25 KHz
        16 KHz
        REPEATS
        63 Hz
        160 Hz
        400 Hz
    */
    
    //delay(VALD); // Delay for valid data    
    return analogRead(CHIP);
}

int strobeChip(int old)
{
    // Will strobe the filter chip
    /* 
    Reset goes high for min of 100us (delay(0.1))
    After a reset: Valid data and output settling time = 208us (delay(0.208))
    Output Settling Time is 36us min (delay(0.036))
    Strobe religiously every 72us (delay(0.072))
    */
    delay(STRD);
    return !old;
}
void nextFilter()
{
    // Will select the next filter on the filter chip
}

void setLEDcolor(int pixelNum, int pot)
{
    // Set the values for the pixels for each row
    int row1 = pixelNum - 1 + (8 * 0);
    int row2 = pixelNum - 1 + (8 * 1);
    int row3 = pixelNum - 1 + (8 * 2);
    int row4 = pixelNum - 1 + (8 * 3);
    int row5 = pixelNum - 1 + (8 * 4);
    int row6 = pixelNum - 1 + (8 * 5);
    int row7 = pixelNum - 1 + (8 * 6);
    int row8 = pixelNum - 1 + (8 * 7);

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
