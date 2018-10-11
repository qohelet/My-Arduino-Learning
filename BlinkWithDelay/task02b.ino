#include "CurieTimerOne.h"

// Comment the following statement to disable logging on serial port.
#define SERIAL_PORT_LOG_ENABLE 1

const int oneSecInUsec = 1000000;   // A second in mirco second unit.
bool toggle = 0;                    // The LED status toggle
int time;                           // the variable used to set the Timer

void timedBlinkIsr()   // callback function when interrupt is asserted
{
  digitalWrite(13, toggle);
  toggle = !toggle;  // use NOT operator to invert toggle value
}

void setup() {

#ifdef SERIAL_PORT_LOG_ENABLE
  Serial.begin(115200);  //  initialize Serial communication
  while (!Serial);       //  wait for the serial monitor to open
#endif

  // Initialize pin 13 as an output - onboard LED.
  pinMode(13, OUTPUT);
}

void loop() {
  for (int counter=0;counter<600; counter++) {
      if (counter <= 300) {
          time = oneSecInUsec / counter;
          CurieTimerOne.start(time, &timedBlinkIsr);
      } else {
          time = oneSecInUsec / (counter*(-1)  +  600);
          CurieTimerOne.start(time, &timedBlinkIsr);
      }
  }
}

void loop3() {

  for (int i = 1; i < 9; i = i * 2) {
    // We set a blink rate of 1000000, 500000, 250000, 125000 microseconds
    time = oneSecInUsec / i; // time is used to toggle the LED is divided by i
    CurieTimerOne.start(time, &timedBlinkIsr);  // set timer and callback

//#ifdef SERIAL_PORT_LOG_ENABLE
//    Serial.print("The blink period: ");
//    Serial.println(time);
//#endif

    //delay(10000);  // 10 seconds of delay, regularly 'interrupted' by the timer interrupt

//#ifdef SERIAL_PORT_LOG_ENABLE
//    Serial.print("Total number of ticks in 10 seconds: ");
//    Serial.println(CurieTimerOne.rdRstTickCount());  // Reads and Resets tick count
//    Serial.println("----");
//#endif
    // Uncomment the following line if the serial logging is disabled
    // CurieTimerOne.restart(time);   // Restarts Timer
  //}
}
