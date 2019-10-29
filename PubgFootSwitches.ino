// Written by Aaron Freedman 03/23/2018

#include <Keyboard.h>

const int resetPin = 12;      // reset pin (on/off switch) pin 12
const int leftBtnPin = 2;     // left button pin 2
const int rightBtnPin = 4;    // right button pin 4
const int ledPin =  13;       // onboard LED pin 13 - for visual feedback

int buttonState1 = 0;         // variable for reading current left button state
int buttonState2 = 0;         // variable for reading current right button state

void setup() {

  pinMode(resetPin, INPUT);     // reset switch set as input 
  pinMode(leftBtnPin, INPUT);   // left button set as input
  pinMode(rightBtnPin, INPUT);  // right button set as input
  pinMode(ledPin, OUTPUT);      // led set as output

  Keyboard.begin();             // initialize control over the keyboard
    
}

void loop() {
  
  digitalWrite(resetPin, HIGH);   // set reset pin to high

  while(digitalRead(resetPin)) {  // run keyboard control while reset switch closed
  }
  
  buttonState1 = digitalRead(leftBtnPin);     // read left button state
  buttonState2 = digitalRead(rightBtnPin);    // read right button state

  if (buttonState1 == HIGH) {     // execute when left NO switch high
    Keyboard.press('q');          // press keystroke 'q'
    digitalWrite(ledPin, HIGH);   // turn led on
    delay(10);                    // delay 10ms
  } 
  else if (buttonState1 == LOW) { // execute when left NO switch low
    Keyboard.release('q');        // release keystroke 'q'
    digitalWrite(ledPin, LOW);    // turn led off
    delay(10);                    // delay 10ms
  } 
 
  if (buttonState2 == HIGH) {     // execute when right NO switch high
    Keyboard.press('e');          // press keystroke 'e'
    digitalWrite(ledPin, HIGH);   // turn led on
    delay(10);                    // delay 10ms
  } 
  else if (buttonState2 == LOW) { // execute when right NO switch low
    Keyboard.release('e');        // release keystroke 'e'
    digitalWrite(ledPin, LOW);    // turn led off
    delay(10);                    // delay 10ms
  }
  
}