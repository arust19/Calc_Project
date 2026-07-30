#include "LedControl.h"

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0, false);   // wake up display
  lc.setIntensity(0, 8);   // brightness 0-15
  lc.clearDisplay(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
