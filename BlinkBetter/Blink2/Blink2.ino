const byte ledPin = 13;
const byte plusbutton = 3;
const byte minusbutton = 2;
volatile int sleeping = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(plusbutton, INPUT_PULLUP);
  pinMode(minusbutton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(plusbutton), inc, FALLING);
  attachInterrupt(digitalPinToInterrupt(minusbutton), dec, FALLING);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(sleeping);
  digitalWrite(ledPin, LOW);
  delay(sleeping);
}

void inc() {
  sleeping -= 50;
}

void dec() {
  sleeping += 50;
}
