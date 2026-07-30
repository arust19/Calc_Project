#include "LedControl.h"

//Map Each button to its corrosponding pin
const int buttonPin# = 2;  // TODO, Map Each button to the coresponding number on calculator to the Pin on the ATTiny

// LedControl for DIN, clck, cs, number of devices
LedControl lc = LedControl(4,5,6,1)  // TODO Double Check pin numbers in Altium!

void setup() {

  // Enable Pull up resistors for each button
  pinMode(buttonPin#, INPUT_PULLUP);

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
  }

  lc.setLed(0,0,0,true) // Set the LED

}
