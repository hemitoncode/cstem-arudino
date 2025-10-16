#include <LedControl.h>

const int DIN = 11;
const int CLK = 13;
const int CS = 3;
const int UNITS = 1;

LedControl lc(DIN,CLK,CS,UNITS);

const int redLight1 = 10;
const int yellowLight1 = 9;
const int greenLight1 = 8;

const int redLight2 = 2;
const int yellowLight2 = 4;
const int greenLight2 = 12;

unsigned int counter = 0;

void setup() {
  pinMode(redLight1, OUTPUT);
  pinMode(yellowLight1, OUTPUT);
  pinMode(greenLight1, OUTPUT);

  pinMode(redLight2, OUTPUT);
  pinMode(yellowLight2, OUTPUT);
  pinMode(greenLight2, OUTPUT);
  lc.shutdown(0, false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}

void runRedLights() {
    digitalWrite(greenLight1, HIGH);
    digitalWrite(yellowLight1, LOW);
    digitalWrite(redLight1, LOW);
    digitalWrite(greenLight2, HIGH);
    digitalWrite(yellowLight2, LOW);
    digitalWrite(redLight2, LOW);
}

void runYellowLights() {
    digitalWrite(greenLight1, LOW);
    digitalWrite(yellowLight1, HIGH);
    digitalWrite(redLight1, LOW);
    digitalWrite(greenLight2, LOW);
    digitalWrite(yellowLight2, HIGH);
    digitalWrite(redLight2, LOW);
}

void runGreenLights() {
    digitalWrite(greenLight1, LOW);
    digitalWrite(yellowLight1, LOW);
    digitalWrite(redLight1, HIGH);
    digitalWrite(greenLight2, LOW);
    digitalWrite(yellowLight2, LOW);
    digitalWrite(redLight2, HIGH);
}

void runSmileyFace() {
  lc.clearDisplay(0);
  lc.setColumn(0, 2, B01100110);
  lc.setColumn(0, 5, B01000010);
  lc.setColumn(0,6,B01111110);
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
  }

  else if (counter == 1) {
    runYellowLights();
    runHLetter();
  }

  else if (counter == 2){
    runGreenLights();
    runILetter();
  }

  counter++;

  // Resetting needs to be below counter++ or else the counter will increment to 1 before next loop 
  if (counter > 2) {
    counter = 0;
  }

  delay(1000);
}
