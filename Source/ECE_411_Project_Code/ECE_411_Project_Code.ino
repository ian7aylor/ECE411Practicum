// Audio Spectrum Equalizer
// By Ali Saad, Marc Merlin, Nick Long 
// ECE 411 Project Code


///////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// Included Libraries /////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////


//Include Library 
#include <FastLED.h>      // Downloaded Library through Arduino IDE application


///////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// Defining Variables ////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////

// Array Assignments 
#define DisplayPin 6      // Output data pin for 8x8 NeoPixel Matrix display 
#define LEDBrightness 63  // Controls Brightness of LED, LEDs set to 1/4th the brightness 
#define NumLEDS 64        // Number of LEDs 8 x 8 = 64
CRGB leds[NumLEDS];       // Sets Arrays of LEDs


//  Analog Input
// Color Assignments for LEDs
#define C0 Black          // no input
#define C1 Red            // 1st column of LEDs
#define C2 Green          // 2nd column of LEDs
#define C3 Blue           // 3rd column of LEDs
#define C4 Yellow         // 4th column of LEDs
#define C5 Purple         // 5th column of LEDs
#define C6 White          // 6th column of LEDs
#define C7 Aqua           // 7th column of LEDs
#define C8 Orange         // 8th column of LEDs

///////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// Intialize Variables ////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

int sensorPin = A0;       // select the input pin for the PotValueentiometer
int resetPin = 3;         // digital pin to reset the mux on the equlizer chip
int strobePin = 4;        // strobe pin to sequence through the mux on the equlizer chip
int MaxS = 0;             // variable to store the value coming from the sensor
int Channel_1 = 0;        // 63 Hz Channel Values,   1st Bandpass Channel
int Channel_2 = 0;        // 160Hz Channel Values,   2nd Bandpass Channel
int Channel_3 = 0;        // 400Hz Channel Values,   3rd Bandpass Channel 
int Channel_4 = 0;        // 1khz Channel Values,    4th Bandpass Channel 
int Channel_5 = 0;        // 2.5khz Channel Values,  5th Bandpass Channel 
int Channel_6 = 0;        // 6.25khz Channel Values, 6th Bandpass Channel 
int Channel_7 = 0;        // 16kHz Channel Values,   7th Bandpass Channel 

// Multiplier for each channel 
// The value we read from ADC will be pretty low so the multiplier will give us 
// a bigger range for the low value, to give an adjustable way for matching that range
int ch1 = 2;              // Channel 1 multiplier
int ch2 = 2;              // Channel 2 multiplier
int ch3 = 2;              // Channel 3 multiplier
int ch4 = 2;              // Channel 4 multiplier
int ch5 = 2;              // Channel 5 multiplier
int ch6 = 2;              // Channel 6 multiplier
int ch7 = 2;              // Channel 7 multiplier


//////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// Setup /////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
// Brought in from the FastLED Library
// Block of memory that will be used for storing and manipulating the led data
// This sets up an array that we can manipulate to set/clear led data. 
// Keepin it simple, a way of addressing the LEDs
  FastLED.addLeds<NEOPIXEL, DisplayPin>(leds, NumLEDS);
 
// Declare the strobePin and resetPin as an OUTPUT:
  pinMode(strobePin, OUTPUT);                         // Seting output for Strobe Pin on Bandpass Filter
  pinMode(resetPin, OUTPUT);                          // Seting output for Reset Pin on Bandpasss Filter 

// Used for diagonositics, let's us see output  
  Serial.begin(115200);                               // Serial Monitor and Baud Rate 
  reset();                                            // Reset the equlizer chip for mux operation, Reset = 1
  digitalWrite(strobePin, HIGH);                      // Set the strobe pin high to initial state, Strobe = 1 
  
// Sets the LED brightness
// Defined in defining variable section
// Now implementing and setting brightness here
  FastLED.setBrightness(LEDBrightness);

}


//////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// Toogle Pin Output /////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////

// Toggle Strobe pin to output the next value from the MUX in the Equalizer Chip
// This dictates which channel to use
void loop() {
  Channel_1 = TogglePinOutput(strobePin, 80)*ch1;   // 63Hz sample  
  DisplayLED(1, Channel_1);                         // Light first column corresponding to input of channel 1
  Channel_2 = TogglePinOutput(strobePin, 80)*ch2;   // 160Hz sample
  DisplayLED(2, Channel_2);                         // Light second column corresponding to input of channel 2
  Channel_3 = TogglePinOutput(strobePin, 80)*ch3;   // 400Hz sample
  DisplayLED(3, Channel_3);                         // Light third column corresponding to input of channel 3
  Channel_4 = TogglePinOutput(strobePin, 80)*ch4;   // 1khz sample
  DisplayLED(4, Channel_4);                         // Light forth column corresponding to input of channel 4
  Channel_5 = TogglePinOutput(strobePin, 80)*ch5;   // 2.5khz sample
  DisplayLED(5, Channel_5);                         // Light fifth column corresponding to input of channel 5
  Channel_6 = TogglePinOutput(strobePin, 80)*ch6;   // 6.25khz sample
  DisplayLED(6, Channel_6);                         // Light sixth column corresponding to input of channel 6
  Channel_7 = TogglePinOutput(strobePin, 80)*ch7;   // 16kHz sample
  DisplayLED(7, Channel_7);                         // Light seventh column corresponding to input of channel 7



//////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////// For LOOP to clear display ///////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////

  
// For loop clears LED display
  for (int j = 0; j < NumLEDS; j++)
    leds[j] = CRGB::C0;                             // Set LEDs to Black, which we also have set for no input 
  FastLED.show();
  
// Diagnostic printing of values read for all 7 channels 
  Serial.println(String("63: " + String(Channel_1) + " 160: " + String(Channel_2) + " 400: " + String(Channel_3) + " 1k: " + String(Channel_4) + " 2.5k: " + String(Channel_5) + " 6.25k: " + String(Channel_6) + " 16k: " + String(Channel_7)));
}

//////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////// Storbe Value //////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////

// Toggle for Strobe pin to get input frequencies
// Refer to Data Sheet if need further understanding  https://www.sparkfun.com/datasheets/Components/General/MSGEQ7.pdf
int TogglePinOutput(int tPin, int timeON) {   // Toggle pin, delay time in microseconds
  digitalWrite(tPin, LOW);                    // Toggle Pin set low, tPin = 0 
  delayMicroseconds(timeON);                  // Delayed need to return a value 
  int sensorValue = analogRead(sensorPin);    // Variable to store the value coming from the sensor
  digitalWrite(tPin, HIGH);                   // Toggle Pin set High, tPin = 1
  delayMicroseconds(timeON);                  // Delay needed to capture a value 
  return sensorValue;                         // Pass the value to find out to decide which channel  
}

void reset() {                                // Reset the mux on the equlizer chip
  digitalWrite(resetPin, HIGH);               // Reset Pin High =1 
  digitalWrite(resetPin, LOW);                // Reset Pin Low = 0
  delayMicroseconds(75);                      // Delay required for how long the reset pin goes high 
                                              // before reset pin goes low  
}

//////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////// Display LEDS //////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////

void DisplayLED(int Col, int PotValue)
{
  // Intialize how high the column goes up  
  int row1 = Col - 1 + (8 * 0);
  int row2 = Col - 1 + (8 * 1);
  int row3 = Col - 1 + (8 * 2);
  int row4 = Col - 1 + (8 * 3);
  int row5 = Col - 1 + (8 * 4);
  int row6 = Col - 1 + (8 * 5);
  int row7 = Col - 1 + (8 * 6);
  int row8 = Col - 1 + (8 * 7);


/* The statements below select which LEDS to light */
// 1st Column LEDs lights row 1-8
  if (PotValue > 15 && PotValue < 255)
  {
    switch (Col)
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


// 2nd Column LEDs lights row 1-8
  if (PotValue > 255 && PotValue < 381)
  {
    switch (Col)
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

// 3rd Column LEDs lights row 1-8
  else if (PotValue > 381 && PotValue < 508)
  {
    switch (Col)
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

// 4th Column LEDs lights row 1-8
  else if (PotValue > 508 && PotValue < 635)
  {
    switch (Col)
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


// 5th Column LEDs lights row 1-8
  else if (PotValue > 635 && PotValue < 762)
  {
    switch (Col)
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

// 6th Column LEDs lights row 1-8
  else if (PotValue > 762 && PotValue < 889)
  {
    switch (Col)
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

// 7th Column LEDs lights row 1-8
  else if (PotValue > 889 && PotValue < 1000)
  {
    switch (Col)
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

// 8th Column LEDs lights row 1-8
  else if (PotValue > 1000 && PotValue < 20000)
  {
    switch (Col)
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
// Actually pushes to the LEDs
    FastLED.show();    
  }
}
