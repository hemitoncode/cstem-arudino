#include <LedControl.h>

const int DIN = 11;
const int CLK = 13;
const int CS = 3;
const int UNITS = 1;

LedControl lc(DIN, CLK, CS, UNITS);

// A lights
const int redLightA = 10;
const int yellowLightA = 9;
const int greenLightA = 8;

// B lights
const int redLightB = 2;
const int yellowLightB = 4;
const int greenLightB = 12;

unsigned int counter = 0;

void setup() {
  pinMode(redLightA, OUTPUT);
  pinMode(yellowLightA, OUTPUT);
  pinMode(greenLightA, OUTPUT);

  pinMode(redLightB, OUTPUT);
  pinMode(yellowLightB, OUTPUT);
  pinMode(greenLightB, OUTPUT);

  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void runRedLights() {
  digitalWrite(greenLightA, HIGH);
  digitalWrite(yellowLightA, LOW);
  digitalWrite(redLightA, LOW);

  digitalWrite(greenLightB, HIGH);
  digitalWrite(yellowLightB, LOW);
  digitalWrite(redLightB, LOW);
}

void runYellowLights() {
  digitalWrite(greenLightA, LOW);
  digitalWrite(yellowLightA, HIGH);
  digitalWrite(redLightA, LOW);

  digitalWrite(greenLightB, LOW);
  digitalWrite(yellowLightB, HIGH);
  digitalWrite(redLightB, LOW);
}

void runGreenLights() {
  digitalWrite(greenLightA, LOW);
  digitalWrite(yellowLightA, LOW);
  digitalWrite(redLightA, HIGH);

  digitalWrite(greenLightB, LOW);
  digitalWrite(yellowLightB, LOW);
  digitalWrite(redLightB, HIGH);
}

void runSmileyFace() {
  lc.clearDisplay(0);
  lc.setColumn(0, 2, B01100110);
  lc.setColumn(0, 5, B01000010);
  lc.setColumn(0, 6, B01111110);
}

void runHLetter() {
  lc.clearDisplay(0);
  lc.setRow(0, 1, B11111111);
  lc.setRow(0, 2, B11111111);
  lc.setRow(0, 5, B11111111);
  lc.setRow(0, 6, B11111111);
  lc.setColumn(0, 3, B01111110);
  lc.setColumn(0, 4, B01111110);
  lc.setColumn(0, 5, B01111110);
}

void runILetter() {
  lc.clearDisplay(0);
  lc.setColumn(0, 2, B00011000);
  lc.setRow(0, 3, B00110111);
  lc.setRow(0, 4, B00110111);
}

void loop() {
  if (counter == 0) {
    runRedLights();
    runSmileyFace();
  } else if (counter == 1) {
    runYellowLights();
    runHLetter();
  } else if (counter == 2) {
    runGreenLights();
    runILetter();
  }

  counter++;

  // Reset counter after reaching the last state
  if (counter > 2) {
    counter = 0;
  }

  delay(1000);
}
