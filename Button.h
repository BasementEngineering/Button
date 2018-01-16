#ifndef BUTTON_H
#define BUTTON_H
#include <Timer.h>
#include <Arduino.h>

class Button{
  
  public:
  Button(int pin);
  virtual void update();
  bool isPressed();
  bool wasReleased();
  bool wasTapped();

protected:
  void checkInput();
  int buttonPin;
  Timer updateTimer;
  bool pressed;
bool releaseDetected ;
  bool tapDetected;
  bool previousReading;
  bool reading;
};

#endif


#ifndef MULTITAPBUTTON_H
#define MULTITAPBUTTON_H
#include <Timer.h>

class MultiTapButton: public Button{
  
public:
MultiTapButton(int pin);
void update() override;
bool wasDoubleTapped();
bool wasLongPressed();
bool isHeldDown();

private:
Timer pressTimer;
Timer pauseTimer;
bool inLongPress;
bool longPressDetected;
bool doubleTapDetected;  
bool ignoreRelease;
void resetStates();
};

#endif
