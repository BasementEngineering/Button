#include "Button.h"

MultiTapButton::MultiTapButton(int pin):
  Button(pin), pressTimer(2000, false), pauseTimer(200, false)
{
  ignoreRelease = false;
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
      detectedAction = DOUBLE_TAP;
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
    detectedAction = SINGLE_TAP;
    pauseTimer.stop();
  }

  if (pressTimer.isFinished()) {
    detectedAction = LONG_PRESS;
    inLongPress = true; 
    ignoreRelease = true;
    pressTimer.stop();
  }
}
}

bool MultiTapButton::wasDoubleTapped() {
  if( detectedAction == DOUBLE_TAP )
  {
    detectedAction = NOTHING;
    return true;
  }
  return false;
}

bool MultiTapButton::wasLongPressed() {
  if( detectedAction == LONG_PRESS )
  {
    detectedAction = NOTHING;
    return true;
  }
  return false;
}

bool MultiTapButton::isHeldDown() {
  return inLongPress;
}

