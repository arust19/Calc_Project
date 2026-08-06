#include "LedControl.h"

//Map Each button to its corrosponding pin

// Used an Array for the 0-9 digits
const int buttonPinsDigits[10] = {14, 11, 15, 13, 12, 16, 10, 9, 17, 18};

// Array to store each opperation, 19 = DIV, 20 = MUL, 21 = SUB, 22 = ADD, 1 = CLR, 24 = EQL
const int buttonPinsOpp[6] = {19, 20, 21, 22, 1, 24};

// Index meanings
#define OPP_DIV 0
#define OPP_MUL 1
#define OPP_SUB 2
#define OPP_ADD 3
#define OPP_CLR 4
#define OPP_EQL 5


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

  for (int i = 0; i < 6; i++){
    pinMode(buttonPinsOpp[i], INPUT_PULLUP);
  }

  // Set up for the MAX display driver
  lc.shutdown(0, false);   // wake up display
  lc.setIntensity(0, 8);   // brightness 0-15
  lc.clearDisplay(0);
}

// Variable to store the col of the calculator, will increase after each number up to 4, then it will loop back to 0
int calcPosition = 0; 
int calcValue = 0;
int calcOpp;


void loop() {

  for(int i = 0; i < 10; i++){
    if(digitalRead(buttonPinsDigits[i]) == LOW){
      //Button i Is pressed - i is the digit value 0-9
      handleDigitPress(i);
    }

    if(i < 7 ){

      if(digitalRead(buttonPinsOpp[i] == LOW && i == OPP_EQL)){
        handleEQLPress();
      }

      else if(digitalRead(buttonPinsOpp[i]) == LOW){
        calcPosition = 0;
        calcOpp = i;

        // Reset the display
        for(int j = 0; j < 4; j++){
          lc.setDigit(0, j, 0, false);
        }
    
      }
    }
  }
}

// This function will handle each digit press
// TODO: Update this section to handle the case where 
void handleDigitPress(int digit){

  //Button Pressed, Add code to display the number/Operator
  if(calcPosition >= 4){ return }
    for(int i = 0; i < 4; i++){
      lc.setDigit(0,calcPosition,i,false) // Turn on one digit (Divice, posititon, value, showDecimal Point)
    }
    calcPosition++;
    calcValue * 10 + digit;    // Update the value so we can perform operations with an actual value - Note that it isnt just adding the numbers together, rather shifting it over a digit and adding the new input
}


// This function will perform the actual operation
void handleEQLPress(){
  switch(calcOpp){
    case OPP_DIV:
    break;

    case OPP_MUL:
    break;

    case OPP_SUB:
    break;

    case OPP_ADD:
    break;

    case OPP_CLR:
    break;

    case OPP_EQL:
    break;
  }
}


