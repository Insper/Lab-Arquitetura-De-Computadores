/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:

#include <Wire.h>
#include <SparkFun_Alphanumeric_Display.h> //Click here to get the library: http://librarymanager/All#Alphanumeric_Display by SparkFun
HT16K33 display;

const int buttonPin = 2;     // the number of the pushbutton pin
const int sensor =  A3;      // the number of the LED pin
const int ground =  A3;      // the number of the LED pin
const int ledPin =  13;      // the number of the LED pin

unsigned long agora = 0;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(sensor, OUTPUT);
  digitalWrite(sensor, HIGH);

   pinMode(ground, OUTPUT);
  digitalWrite(ground, LOW);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  
   
  Wire.begin(); //Join I2C bus
   
    
    
    if (display.begin() == false)
  {
    Serial.println("Device did not acknowledge! Freezing.");
    while (1);
  }
  
  display.print("  4.5");
  display.decimalOn();// --- Turn the decimal on for all displays on bus
  //

  //Teste PInSensor
  /*
  Serial.println("Teste PInSensor");
  for(int i = 0; i<10; i++)
  {
  digitalWrite(sensor, LOW);
    delay(500);
    digitalWrite(sensor, HIGH);
    delay(500);
  }
  */
  
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
 

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {

    digitalWrite(ledPin, HIGH);
    // turn LED on:
    agora = millis();
  display.print("R 5.5");
  Serial.println("R 5.5");
  display.decimalOn();// --- Turn the decimal on for all displays on bus
  while(millis() < (agora + 5000)) {
    
    if (digitalRead(buttonPin) == HIGH) break;
    
    digitalWrite(sensor, LOW);
    delayMicroseconds(10);
    digitalWrite(sensor, HIGH);
    delay(1045);
    
  }

agora = millis();
  display.print("R 4.5");
  Serial.println("R 4.5");
  display.decimalOn();// --- Turn the decimal on for all displays on bus
  while(millis() < (agora + 5000)) {
        
    if (digitalRead(buttonPin) == HIGH) break;
    
    digitalWrite(sensor, LOW);
    delayMicroseconds(10);
    digitalWrite(sensor, HIGH);
    delay(1277);
    
  }

agora = millis();
  display.print("R 3.5");
  Serial.println("R 3.5");
  display.decimalOn();// --- Turn the decimal on for all displays on bus
  while(millis() < (agora + 5000)) {
        
    if (digitalRead(buttonPin) == HIGH) break;
    
    digitalWrite(sensor, LOW);
    delayMicroseconds(10);
    digitalWrite(sensor, HIGH);
    delay(1642);
    
  }

agora = millis();
  display.print("R 2.5");
  Serial.println("R 2.5");
  display.decimalOn();// --- Turn the decimal on for all displays on bus
  while(millis() < (agora + 5000)) {
        
    if (digitalRead(buttonPin) == HIGH) break;
    
    digitalWrite(sensor, LOW);
    delayMicroseconds(10);
    digitalWrite(sensor, HIGH);
    delay(2298);
    
  }

agora = millis();
  display.print("R 1.5");
  Serial.println("R 1.5");
  display.decimalOn();// --- Turn the decimal on for all displays on bus
  while(millis() < (agora + 5000)) {
        
    if (digitalRead(buttonPin) == HIGH) break;
    
    digitalWrite(sensor, LOW);
    delayMicroseconds(10);
    digitalWrite(sensor, HIGH);
    delay(3830);
    
  }

agora = millis();
  display.print("R 0.5");
  Serial.println("R 0.5");
  display.decimalOn();// --- Turn the decimal on for all displays on bus
  while(millis() < (agora + 5000)) {
        
    if (digitalRead(buttonPin) == HIGH) break;
    
    digitalWrite(sensor, LOW);
    delayMicroseconds(10);
    digitalWrite(sensor, HIGH);
    delay(11491);
    
  }

  agora = millis();
  display.print("R 1.5");
  Serial.println("R 1.5");
  display.decimalOn();// --- Turn the decimal on for all displays on bus
  while(millis() < (agora + 5000)) {
        
    if (digitalRead(buttonPin) == HIGH) break;
    
    digitalWrite(sensor, LOW);
    delayMicroseconds(10);
    digitalWrite(sensor, HIGH);
    delay(3830);
    
  }


  agora = millis();
  display.print("R 2.5");
  Serial.println("R 2.5");
  display.decimalOn();// --- Turn the decimal on for all displays on bus
  while(millis() < (agora + 5000)) {
        
    if (digitalRead(buttonPin) == HIGH) break;
    
    digitalWrite(sensor, LOW);
    delayMicroseconds(10);
    digitalWrite(sensor, HIGH);
    delay(2298);
    
  }


  agora = millis();
  display.print("R 3.5");
  Serial.println("R 3.5");
  display.decimalOn();// --- Turn the decimal on for all displays on bus
  while(millis() < (agora + 5000)) {
        
    if (digitalRead(buttonPin) == HIGH) break;
    
    digitalWrite(sensor, LOW);
    delayMicroseconds(10);
    digitalWrite(sensor, HIGH);
    delay(1642);
    
  }

agora = millis();
  display.print("R 4.5");
  Serial.println("R 4.5");
  display.decimalOn();// --- Turn the decimal on for all displays on bus
  while(millis() < (agora + 5000)) {
        
    if (digitalRead(buttonPin) == HIGH) break;
    
    digitalWrite(sensor, LOW);
    delayMicroseconds(10);
    digitalWrite(sensor, HIGH);
    delay(1277);
    
  }
  } 
  
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);

   //agora = millis();
  display.print("C 5.5");
  Serial.println("C 5.5");
  display.decimalOn();// --- Turn the decimal on for all displays on bus
  while(digitalRead(buttonPin) == HIGH)
  {
   // agora = millis();
  //while(millis() < (agora + 5000)) {
    
    //if (digitalRead(buttonPin) == HIGH) break;
    //Serial.println("C 5.5");
    digitalWrite(sensor, LOW);
    delayMicroseconds(10);
    digitalWrite(sensor, HIGH);
    delay(1045);
  //}
  }
  }
  
  

  
  
  
}
