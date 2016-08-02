#include "DigiKeyboard.h"

#define PB0 0
#define PB1 1
#define PB2 2
#define PB5 5

int _inputs[4] = {LOW, LOW, LOW, LOW};
int _keyStates[4] = {LOW, LOW, LOW, LOW};
int _outputKeys[4] = {KEY_A, KEY_S, KEY_D, KEY_F};

void setup() {
  // I/O
  pinMode(PB0, INPUT);
  digitalWrite(PB0, HIGH);
  pinMode(PB1, INPUT);
  digitalWrite(PB1, HIGH);
  pinMode(PB2, INPUT);
  digitalWrite(PB2, HIGH);
  pinMode(PB5, INPUT);
  digitalWrite(PB5, HIGH);
}

void ReadInputs()
{
  _inputs[0] = digitalRead(PB0);
  _inputs[1] = digitalRead(PB1);
  _inputs[2] = digitalRead(PB2);
  _inputs[3] = digitalRead(PB5);
}

void SendKey(int keyIndex)
{
  // Neg-edge
  if (_inputs[keyIndex] == LOW && _keyStates[keyIndex] == HIGH)
  {
    // Press
    DigiKeyboard.sendKeyPress(0);
    DigiKeyboard.sendKeyPress(_outputKeys[keyIndex]);
    _keyStates[keyIndex] = _inputs[keyIndex];
  }
  // Pos-edge
  else if (_inputs[keyIndex] == HIGH && _keyStates[keyIndex] == LOW)
  {
    // Release
    DigiKeyboard.sendKeyPress(0);
    _keyStates[keyIndex] = _inputs[keyIndex];
  }
}

void SendKeys()
{
  for (int i = 0; i < 4; i++)
  {
    SendKey(i);
  }
}

void loop() {
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  //DigiKeyboard.sendKeyStroke(0);

  ReadInputs();
  SendKeys();

  DigiKeyboard.delay(25);
}
