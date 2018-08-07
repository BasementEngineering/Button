//EXPERIMENTAL!

#include "Button.h"

enum valueTypes {UNKNOWN_VALUE, NO_BUTTON_PRESS, BUTTON_PRESS};

AnalogKeypadButton::AnalogKeypadButton(int analogPin, int analogValue, int zeroValue):
  MultiTapButton(analogPin)
{
  lastValueType = NO_BUTTON_PRESS;
  noPressValue = zeroValue;
  buttonValue = analogValue;
}

void AnalogKeypadButton::checkInput(void) {
  
  const uint8_t tolerance = 6;
  
  previousReading = reading;
  int inputValue = analogRead(buttonPin);
  
  if ( withinTolerance(inputValue, buttonValue, tolerance) )
  {
    if( measuredTwice(BUTTON_PRESS) )
    {
       reading = 1;
    }
  }
  else if ( withinTolerance(inputValue, noPressValue, tolerance) )
  {
    if( measuredTwice(NO_BUTTON_PRESS) )
    {
       reading = 0;
    }
  }
  else
  {
    if( measuredTwice(UNKNOWN_VALUE) )
    {
        reading = 0;
        previousReading = 0;
        resetTapDetection();
    }
  }
}

bool AnalogKeypadButton::withinTolerance(int value, int goal, int tolerance)
{
  return ( (goal - tolerance) < value ) && ( value < (goal + tolerance) );
}

bool AnalogKeypadButton::measuredTwice(int valueType)
{
  const int maxCounterValue = 2;
  
  if (lastValueType != valueType)
    {
      lastValueType = valueType;
      counter = 1;
      return false;
    }
    else
    {
      if (counter > maxCounterValue)
      {
        counter++;
        return false;
      }
      else
      {
        return true;
      }
    }
}

void AnalogKeypadButton:: resetTapDetection(void)
{
  pressTimer.stop();
  pauseTimer.stop();
  inLongPress = false;
  ignoreRelease = false;
}

