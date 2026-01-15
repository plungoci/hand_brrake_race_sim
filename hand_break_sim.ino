//This script is written to control the handbrake, and to then send the input to the PC

//Define our Handbrake Pin
#define HPIN A7

// Initialize PC input objects
#include <Joystick.h>

//Create Joystick object
Joystick_ Joystick(0x03,JOYSTICK_TYPE_JOYSTICK,1,0);

void setup() {
  pinMode(HPIN, INPUT);

  //Initialize Joystick Library
  Joystick.begin(false);
  Joystick.setRxAxisRange(0,255); // Rx - axis will be our Handbrake
}

void loop() {
  // HANDBRAKE
  int hval2 = analogRead(HPIN);
  int hmax = 494;
  int hmin = 81;
  int hval3 = abs(hval2-hmax);
  double hval4 = (double(hval3)/(hmax-hmin));
  int hval5 = int(hval4*255);
   if (hval5>255) {
    hval5=255;
  }
  else if (hval5<6){
    hval5=0;
  }

  Joystick.setRxAxis(hval5);
  Joystick.sendState();
  delay(10);
}
