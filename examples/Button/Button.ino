#include "Button.h"

Button testButton(8);

void setup() {
  Serial.begin(9600);
  Serial.println("Serial Debugging enabled");
}

void loop() {
	
//Update will check your input every 20ms
testButton.update();

if(testButton.wasTapped()){
  Serial.println("Tap detected");
}

}
