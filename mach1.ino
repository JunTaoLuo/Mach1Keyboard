#include "DigiKeyboard.h"

#define PB0 0
#define PB1 1
#define PB2 2
#define PB5 5

int Key1State = HIGH;
int Key2State = HIGH;
int Key3State = HIGH;
int Key4State = HIGH;

int Key1 = KEY_1;
int Key2 = KEY_2;
int Key3 = KEY_3;
int Key4 = KEY_4;

int input = HIGH;

void setup() {
  // don't need to set anything up to use DigiKeyboard
  pinMode(PB0, INPUT);
  digitalWrite(PB0, HIGH);
  pinMode(PB1, INPUT);
  digitalWrite(PB1, HIGH);
  pinMode(PB2, INPUT);
  digitalWrite(PB2, HIGH);
  pinMode(PB5, INPUT);
  digitalWrite(PB5, HIGH);
}

void loop() {
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  //DigiKeyboard.sendKeyStroke(0);
  
  // Key 1
  input = digitalRead(PB0);
  if (input == LOW && Key1State == HIGH)
  {
    // Press
    DigiKeyboard.sendKeyPress(0);
    DigiKeyboard.sendKeyPress(Key1);
    Key1State = input;
  }
  else if (input == HIGH && Key1State == LOW)
  {
    // Release
    DigiKeyboard.sendKeyPress(0);
    Key1State = input;
  }

  // Key 1
  input = digitalRead(PB1);
  if (input == LOW && Key2State == HIGH)
  {
    // Press
    DigiKeyboard.sendKeyPress(0);
    DigiKeyboard.sendKeyPress(Key2);
    Key2State = input;
  }
  else if (input == HIGH && Key2State == LOW)
  {
    // Release
    DigiKeyboard.sendKeyPress(0);
    Key2State = input;
  }

  // Key 1
  input = digitalRead(PB2);
  if (input == LOW && Key3State == HIGH)
  {
    // Press
    DigiKeyboard.sendKeyPress(0);
    DigiKeyboard.sendKeyPress(Key3);
    Key3State = input;
  }
  else if (input == HIGH && Key3State == LOW)
  {
    // Release
    DigiKeyboard.sendKeyPress(0);
    Key3State = input;
  }

  // Key 1
  input = digitalRead(PB5);
  if (input == LOW && Key4State == HIGH)
  {
    // Press
    DigiKeyboard.sendKeyPress(0);
    DigiKeyboard.sendKeyPress(Key4);
    Key4State = input;
  }
  else if (input == HIGH && Key4State == LOW)
  {
    // Release
    DigiKeyboard.sendKeyPress(0);
    Key4State = input;
  }

  DigiKeyboard.delay(25);
}
