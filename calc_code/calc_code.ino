#include "LedControl.h"

//Map Each button to its corrosponding pin
const int buttonPin0 = 14;  // TODO, Map Each button to the coresponding number on calculator to the Pin on the ATTiny
const int buttonPin1 = 11;
const int buttonPin2 = 15;
const int buttonPin3 = 13;
const int buttonPin4 = 12;
const int buttonPin5 = 16;
const int buttonPin6 = 10;
const int buttonPin7 = 9;
const int buttonPin8 = 17;
const int buttonPin9 = 18;

const int buttonPinDIV = 19;
const int buttonPinMUL = 20;
const int buttonPinSUB = 21;
const int buttonPinADD = 22;

const int buttonPinCLR = 1;
const int buttonPinEQL = 24;

// Code for button debouncing
unsigned long buttonPressCount = 0;
const unsigned long buttonMax = 50;

// LedControl for DIN, clck, cs, number of devices
LedControl lc = LedControl(6,5,7,1)  // TODO Double Check pin numbers in Altium!

void setup() {

  // Enable Pull up resistors for each button
  for(int i=0; i<10; i++){
    pinMode(buttonPin+i+, INPUT_PULLUP);
  }

  pinMode(buttonPinDIV, INPUT_PULLUP);
  pinMode(buttonPinMUL, INPUT_PULLUP);
  pinMode(buttonPinSUB, INPUT_PULLUP);
  pinMode(buttonPinADD, INPUT_PULLUP);
  pinMode(buttonPinCLR, INPUT_PULLUP);
  pinMode(buttonPinEQL, INPUT_PULLUP);

  // Set up for the MAX display driver
  lc.shutdown(0, false);   // wake up display
  lc.setIntensity(0, 8);   // brightness 0-15
  lc.clearDisplay(0);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Check for button press - Button not pressed = HIGH (pull-UP Resistor)
  if(digitalRead(buttonPin#) == LOW){
    //Button Pressed, Add code to display the number/Operator
    lc.setLED(0,0,0,true) // Turn on one LED (Divice, Row, Col, State)
  }

  lc.setLed(0,0,0,true) // Set the LED

}
