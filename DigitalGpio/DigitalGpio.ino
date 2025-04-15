buttonPin = 2
lightPin = LED_BUILTIN

void setup() {
  pinMode(2);
  pinMode(LED_BUILTIN);
}

void loop() {
  if(digitalRead(buttonPin) == HIGH)
  {
    digitalWrite(lightPin,HIGH);
  }
}
