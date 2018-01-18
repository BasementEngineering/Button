# Button

If you want to hook your arduino project up with a couple of buttons, this is the library for you.
It allows you to call simple Button objects that take care of all of the debouncing or 
MultiTapButtons, that can destinguish between a simple tap, a double tap and a long press.

This library relies on the Timer library that can be found here https://github.com/BasementEngineering/Timer

Here you can see how the different signals look:

simple Button:
                     +-------- Tap Detected!
                     |
                     |
                     v
           +---------+
           |         |
           |         |
           |         |
  +--------+         +----------------------------------------------+



MultiTapButton:
                               +-------- Tap Detected!
                               |
                               |
                               v
           +---------+  after
           |         |  200ms
           |         |
           |         |
  +--------+         +----------------------------------------------+


                            +-------- Double Tap Detected!
                            |
                            |
                            v
           +--------+       +-------+
           |        | max   |       |
           |        | 200ms |       |
           |        |       |       |
  +--------+        +-------+       +-------------------------------+


                                            +--------+ Long Press Detected!
                                            |
                                            v
           +-------------------------------------------+
           |                                           |
           |               min 2000ms                  |
           |                                           |
  +--------+                                           +------------+



