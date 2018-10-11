/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  for (int counter=0;counter<300; counter++) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(counter);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(counter);               // wait for a second
  }
  for (int counter=0;counter<300; counter--) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(300-counter);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
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

