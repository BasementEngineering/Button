#include "Button.h"

MultiTapButton::MultiTapButton(int pin):
  Button(pin), pressTimer(2000, false), pauseTimer(200, false)
{
  ignoreRelease = false;
  resetStates();
}

void MultiTapButton::update() {

if(updateTimer.isFinished()){
  checkInput();

  if (reading && !previousReading) {
    releaseDetected = false;
    pressed = true;
    if (!pauseTimer.isActive()){
      pressTimer.start();
    }
    else if( pauseTimer.isActive() ){
      resetStates();
      doubleTapDetected = true;
      ignoreRelease = true;
      pauseTimer.stop();
    }
  }
  else if (previousReading && !reading) {
    inLongPress = false;
    pressed = false;
    releaseDetected = true;
    if(!ignoreRelease){
      pressTimer.stop();
      pauseTimer.start();
    }
    else{
      ignoreRelease = false;
    }
  }

  if (pauseTimer.isFinished()) {
    resetStates();
    tapDetected = true;
    pauseTimer.stop();
  }

  if (pressTimer.isFinished()) {
    resetStates();
    longPressDetected = true; 
    inLongPress = true; 
    ignoreRelease = true;
    pressTimer.stop();
  }
}
}

bool MultiTapButton::wasDoubleTapped() {
  bool doubleTapped = doubleTapDetected;
  doubleTapDetected = false;
  return doubleTapped;
}

bool MultiTapButton::wasLongPressed() {
  bool longPressed = longPressDetected;
  longPressDetected = false;
  return longPressed;
}

bool MultiTapButton::isHeldDown() {
  return inLongPress;
}

void MultiTapButton::resetStates() {
  tapDetected = false;
  doubleTapDetected = false;
  longPressDetected = false;
}

