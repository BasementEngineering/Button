#include "Button.h"

//Analog Button Values
//(1) 732  (2) 680  (3) 639
//(4) 927  (5) 854  (6) 790
//(Mic) 1020
//No Press 600

AnalogKeypadButton button0(A1, 1020, 600);

AnalogKeypadButton button1(A1,  732, 600);
AnalogKeypadButton button2(A1, 680, 600);
AnalogKeypadButton button3(A1, 639, 600);
AnalogKeypadButton button4(A1, 927, 600);
AnalogKeypadButton button5(A1, 854, 600);
AnalogKeypadButton button6(A1, 790, 600);

AnalogKeypadButton buttons[7] = {button0, button1, button2, button3, button4, button5, button6};
void setup() {
  Serial.begin(9600);

}

void loop() {
  for (int i = 0; i < 7; i++)
  {
    buttons[i].update();

    if (buttons[i].wasTapped()) {
      Serial.print("Button "); Serial.println(i);
      Serial.println("Tap detected");
    }
    else if (buttons[i].wasDoubleTapped()) {
      Serial.print("Button "); Serial.println(i);
      Serial.println("Double tap detected");
    }
    else if (buttons[i].wasLongPressed()) {
      Serial.print("Button "); Serial.println(i);
      Serial.println("Long press detected");
    }
  }


}
