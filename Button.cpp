#include "Button.h"

Button::Button(int pin):
updateTimer(20, true)
{
  buttonPin = pin;
  pinMode(buttonPin, INPUT);
  pressed = false;
releaseDetected  = false;
  tapDetected = false;
  reading = false;
  previousReading = false;
  updateTimer.start();
}

bool Button::wasTapped(){
  bool tapped = tapDetected;
  tapDetected = false;
  return tapped;
}

bool Button::wasReleased(){
  bool released = releaseDetected;
  releaseDetected = false;
  return released;
}

bool Button::isPressed(){
  return pressed;
}

void Button::update(){
if(updateTimer.isFinished()){
checkInput();

  if(reading && !previousReading){
    releaseDetected = false;
    pressed = true;
    tapDetected = true;
  }
  else if(previousReading && !reading){
    pressed = false;
    releaseDetected = true;
  }
}
}

void Button::checkInput(){
  previousReading = reading;
  reading = digitalRead(buttonPin);
}

