#include <Joystick.h>

// Create the Joystick
Joystick_ Joystick;

// suggested pin usage
// 0,1,2 - pins for 5 position selector (flight modes)
// 3,4,5 - pins for 5 position selector (nav modes)
// 6 - gear
// 7 - hook
// 8 - hud power
// 9 - hud declutter
//10 = hud awl
//11 = vdi power
//12 = vdi mode
//13 = vdi awl
//18a0 = hsd power
//19a1 = hsd nav
//20a2 = hsd ecm
//21a3 = hsd ecm oride
//22a4 = master arm
//23a5 = master training

void setup() {
  // Initialize Button Pins
  // set pins to use internal pullup
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
}

// Last state of the button
// note analog pins are index 18-23 (buttons 19-24)
// digital pins are 0-13 (buttons 1-14)
int lastButtonState[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void loop() {

  // Read pin values
  for (int index=0; index < 24; index++)
  {
    int currentButtonState = !digitalRead(index);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index,currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
  // Read compound-pin values
  // you can use a "shift register" or 
  // circuit logic to reduce button usage to 
  // just enough buttons to cover the bitwise combinations
  // 000
  // 001
  // 010
  // 011
  // 100
  // 101
  // 110
  // 111
  
  if (lastButtonState[0]>0 and lastButtonState[1]>0){
    Joystick.setButton(31,1);
  } else {
    Joystick.setButton(31,0);
  }
  delay(50);
}
