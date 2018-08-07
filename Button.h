#ifndef BUTTON_H
#define BUTTON_H
#include <Timer.h>
#include <Arduino.h>

enum actions {NOTHING,SINGLE_TAP,DOUBLE_TAP,LONG_PRESS};

class Button{
  
  public:
  Button(int pin);
  virtual void update(void);
  bool isPressed(void);
  bool wasReleased(void);
  bool wasTapped(void);

protected:
  virtual void checkInput(void);
  int buttonPin;
  Timer updateTimer;
  bool pressed;
  bool releaseDetected ;
  int detectedAction;
  bool previousReading;
  bool reading;
};

#endif


#ifndef MULTITAPBUTTON_H
#define MULTITAPBUTTON_H
#include <Timer.h>
#include <Arduino.h>

class MultiTapButton: public Button{
  
public:
MultiTapButton(int pin);
void update(void) override;
bool wasDoubleTapped(void);
bool wasLongPressed(void);
bool isHeldDown(void);

protected:
Timer pressTimer;
Timer pauseTimer;
bool inLongPress;
bool ignoreRelease;
};

#endif

#ifndef ANALOGKEYPADBUTTON_H
#define ANALOGKEYPADBUTTON_H
#include <Timer.h>
#include <Arduino.h>

class AnalogKeypadButton: public MultiTapButton{
  
public:
AnalogKeypadButton(int analogPin, int analogValue, int zeroValue = 0);

private:
int buttonValue;
int noPressValue;
int lastValueType;
int counter;

void checkInput(void) override;
bool withinTolerance(int value, int goal, int tollerance);
bool measuredTwice(int valueType);
void resetTapDetection(void);
};

#endif
