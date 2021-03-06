/*
  Input Pull-up Serial

  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 2 and prints the results to the Serial Monitor.

  The circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. This configuration causes the input to read
  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/InputPullupSerial
*/

  int counter=0;
  bool was_on=false;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void blinken(){
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(35);                       // wait for a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(25);    
}

void loop() {
  
  int sensorVal = digitalRead(2);

  
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);  
    was_on=true;
  } else {
    blinken();
    if(was_on)
    {
      counter++;
      Serial.print("LED is ON for the ");
      Serial.print(counter); //int here
      Serial.print("th time");
      Serial.println();      //change line      
    }
    
    was_on=false;
  }



  
} 
