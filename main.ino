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

void loop() {
  if (counter == 0) {
    runRedLights();
  }

  else if (counter == 1) {
    runYellowLights();
  }

  else if (counter == 2){
    runGreenLights();
  }

  counter++;

  // Resetting needs to be below counter++ or else the counter will increment to 1 before next loop 
  if (counter > 2) {
    counter = 0;
  }

  delay(1000);
}
