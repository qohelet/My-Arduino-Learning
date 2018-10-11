const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  // attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
  attachInterrupt(interruptPin, blink, CHANGE);
}

void loop() {
  // digitalWrite(ledPin, state);
  for (int counter=0;counter<300; counter++) {
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(counter);               // wait for a second
    digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
    delay(counter);               // wait for a second
  }
  for (int counter=0;counter<300; counter++) {
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(300-counter);               // wait for a second
    digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
    delay(300-counter);               // wait for a second
  }
}


void loop2() {
  // digitalWrite(ledPin, state);
  for (int counter=0;counter<600; counter++) {
      if (counter <= 300) {
        digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(counter);               // wait for a second
        digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
        delay(counter);               // wait for a second
      } else {
        digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(counter*(-1)  +  600);               // wait for a second
        digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
        delay(counter*(-1)  +  600);               // wait for a second
      }
  }
}

void blink() {
  state = !state;
}
