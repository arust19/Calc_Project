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


int calcPosition = 0;    // Variable to store the col of the calculator, will increase after each number up to 4, then it will loop back to 0
int calcValueOne = 0;    // First operand 
int calcValueTwo = 0;    // Second operand
int operand = 0;         // Variable to store if using operand 1 or 2, increments only when an operation is selected
int calcOpp;             // Variable to store what operation was selected
int calcFinalVal = 0;    // Variable to store the result of the operation

// TODO: Add button debouncing
void loop() {

  for(int i = 0; i < 10; i++){
    if(digitalRead(buttonPinsDigits[i]) == LOW){
      //Button i Is pressed - i is the digit value 0-9
      handleDigitPress(i);
    }

    if(i < 6 ){

      // Handle the case where Equal is selected 
      if(digitalRead(buttonPinsOpp[i]) == LOW && i == OPP_EQL)){
        handleEQLPress();
      }

      // Handle the case where Clear is selected
      else if(digitalRead(buttonPinsOpp[i]) == LOW && i == OPP_CLR)){
        // Reset all settings
        for(int j = 0; j < 4; j++){
          lc.setDigit(0, j, 0, false);
        }

        calcPosition = 0;
        calcValueOne = 0;
        calcValueTwo = 0;
        operand = 0;
       
      }

      // Should only run on a valid operation, and NOT EQL / CLR
      else if(digitalRead(buttonPinsOpp[i]) == LOW){
        calcPosition = 0;
        calcOpp = i;
        operand++;    // Move to the next operand once an operation is selected

        // Reset the display
        for(int j = 0; j < 4; j++){
          lc.setDigit(0, j, 0, false);
        }
    
      }
    }
  }
}

// This function will handle each digit press 
void handleDigitPress(int digit){

  //Button Pressed, Add code to display the number/Operator
  if(calcPosition >= 4){ return; }

    // Turn on one digit (Divice, posititon, value, showDecimal Point)
    lc.setDigit(0,calcPosition,i,false); 

    if(operand == 0){
      calcValueOne = calcValueOne * 10 + digit;
    }
    else if(operand == 1){
      calcValueTwo = calcValueTwo * 10 + digit;
    }
    calcPosition++;
    
}


// This function will perform the actual operation
// TODO: Add helper function to display the result
void handleEQLPress(){
  switch(calcOpp){
    case OPP_DIV:
    // Guard against div by 0
    if(calcValueTwo != 0){
      calcFinalVal = calcValueOne / calcValueTwo;
    }
    break;

    case OPP_MUL:
    calcFinalVal = (calcValueOne * calcValueTwo);
    break;

    case OPP_SUB:
    calcFinalVal = (calcValueOne - calcValueTwo);
    break;

    case OPP_ADD:
    calcFinalVal = (calcValueOne + calcValueTwo);
    break;
  }
}


