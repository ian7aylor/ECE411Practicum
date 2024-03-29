#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/


//Globals and initializations
String S1, S2, S3, string;

 Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 11,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  S1 = String("Band1 ");
  S2 = String("Band2 ");
  S3 = String("Band3 ");
  string = String();


  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);

}
int x    = matrix.width();
int pass = 0;

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
int sensorValue1 = analogRead(A0);
int sensorValue2 = analogRead(A1);
int sensorValue3 = analogRead(A2);
  // print out the value you read:
   //1st band
  string = S1 + sensorValue1;
   Serial.println(string);
   //2nd band
  string = S2 + sensorValue2;
   Serial.println(string);
   //3rd band
 string = S3 + sensorValue3;
  Serial.println(string);
  delay(1);        // delay in between reads for stability
 
 // Check if voltage is greater than 0 and print to Led1
if (sensorValue1 > 0){
loop1();
}
// Check if voltage is greater than 0 and print to Led3
if (sensorValue2 > 0){
loop1();
}
if (sensorValue3 > 0){
loop1();
}
}
  void loop1() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(F("Howdy"));
  if(--x < -36) {
    x = matrix.width();
    if(++pass >= 3) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(100);
}
