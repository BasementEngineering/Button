#include "Button.h"

MultiTapButton testButton(8);

void setup() {
  Serial.begin(9600);
  Serial.println("Serial Debugging enabled");
}


void loop() {
testButton.update();
if(testButton.wasTapped()){
  Serial.println("Tap detected");
}
else if(testButton.wasDoubleTapped()){
  Serial.println("Double tap detected");
}
else if(testButton.wasLongPressed()){
  Serial.println("Long press detected");
}
}
