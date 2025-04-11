#include "arduino_secrets.h"

/*

*/

void setup() {
  //No need to set pin mode for analog
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A0); // read the input pin
  Serial.println(val);      // print debug value
  delay(10);                // delay a little bit to improve performance
}
