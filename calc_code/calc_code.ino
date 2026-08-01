#include "LedControl.h"

//Map Each button to its corrosponding pin

// Used an Array for the 0-9 digits
const int buttonPinsDigits[10] = {14, 11, 15, 13, 12, 16, 10, 9, 17, 18};
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
LedControl lc = LedControl(6,5,7,1);  // TODO Double Check pin numbers in Altium!

void setup() {

  // Enable pull-up resistors for digit buttons
  for (int i = 0; i < 10; i++) {
    pinMode(buttonPinsDigits[i], INPUT_PULLUP);
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
