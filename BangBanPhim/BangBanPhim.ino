#include <Keypad.h>

const int stepsPerRevolution = 2048;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
int motorPins[] = {10, 11, 12, 13};
int motorSequence[][4] = {
  {1, 0, 0, 1},
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1}
};
int currentPosition = 0;
int direction = 1;
int previousStep = -1;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(motorPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key == 'A') {
      direction = -1;
    } else if (key == 'D') {
      direction = 1;
    } else {
      int steps = key - '0';
      int targetPosition = currentPosition + (steps * direction * 512);
      targetPosition = targetPosition % stepsPerRevolution;
      if (targetPosition < 0) {
        targetPosition += stepsPerRevolution;
      }
      Serial.print("Moving ");
      Serial.print(steps);
      Serial.print(" steps ");
      if (direction == 1) {
        Serial.println("clockwise");
      } else {
        Serial.println("counterclockwise");
      }
      while (currentPosition != targetPosition) {
        int step = currentPosition % 8;
        if (step != previousStep) {
          for (int i = 0; i < 4; i++) {
            digitalWrite(motorPins[i], motorSequence[step][i]);
          }
          previousStep = step;
        }
        if (direction == 1) {
          currentPosition++;
        } else {
          currentPosition--;
        }
        if (currentPosition < 0) {
          currentPosition = stepsPerRevolution - 1;
        }
        delayMicroseconds(1000);
      }
    }
  }
}