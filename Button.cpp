#include "Button.h"

Button::Button(int pin):
updateTimer(20, true)
{
  buttonPin = pin;
  pinMode(buttonPin, INPUT);
  pressed = false;
  releaseDetected  = false;
  detectedAction = NOTHING;
  reading = false;
  previousReading = false;
  updateTimer.start();
}

bool Button::wasTapped(){
  if(detectedAction == SINGLE_TAP)
  {
    detectedAction = NOTHING;
    return true;
  }
  return false;
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
    detectedAction = SINGLE_TAP;
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

