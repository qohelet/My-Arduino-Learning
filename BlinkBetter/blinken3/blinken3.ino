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
  bool was_on=false, herzy_on=false;
  int blink_mode=0;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void blinken(int d1, int d2){
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(d1);                       // wait for a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(d2);    
}

void counteroutput(){
      Serial.print("LED is ON for the ");
      Serial.print(counter); //int here
      Serial.print("th time");
      Serial.println();      //change line     
}
void herzyoutput(){
    static int herzycounter=0;
    Serial.print("Herzy was pressed ");
    Serial.print(herzycounter);
    Serial.print(" times and switched to ");
    switch(blink_mode){
          case 0:
            Serial.print("20/20");
            break;
          case 1:
            Serial.print("80/100");
            break;
          case 2:
            Serial.print("20/120");
            break;
          case 3:            
              Serial.print("loop");
              break;
          default:
              Serial.print("Random");
            break;
        
        }  
    Serial.println();
    herzycounter++;
}

void doBlink(){
  switch(blink_mode){
          case 0:
            blinken(20,20);
            break;
          case 1:
            blinken(80,100);           
            break;
          case 2:
            blinken(20,120);
            break;
          case 3:            
              for(int i=10;i<50;i+=20)
                blinken(i,i/10);
              break;
          default:
              int r_1 = random(5,400);
              int r_2 = random(4,500);
              blinken(r_1,r_2);
              blinken(r_2,r_1);
            break;
        
        }
  }

void blinkLogik(){
  blink_mode++;
        if(blink_mode>=5)
          blink_mode=0;  
  }

unsigned long herzytime = millis();

void loop() {
  int sensorVal = digitalRead(2);
  int herzy = digitalRead(4);

    if(herzy == LOW){ //Herzy is pressed
      unsigned long current = millis();

      if (current - herzytime > 20 && herzy_on==false){ //Press was long time ago
        blinkLogik();
        herzyoutput();
        herzytime = current;
    }
    herzy_on=true;
  }
  else{
    herzy_on=false;
  }

  //Light Switch
  if (sensorVal != HIGH) {
    digitalWrite(13, LOW);  
    was_on=true;
  } else {
      doBlink();
    if(was_on)
    {
      counter++;
      counteroutput(); 
    }        
    was_on=false;
  }



  
} 
