// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#define PIN_LED 13
#define PIN_BUTTON1 10
#define PIN_BUTTON2 11

int LED_Delay = 3000;

void setup() {
  pinMode(PIN_LED,     OUTPUT);
  pinMode(PIN_BUTTON1, INPUT);
  pinMode(PIN_BUTTON2, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(PIN_BUTTON1) == HIGH){
    LED_Delay /= 2;
  } else if (digitalRead(PIN_BUTTON2) == HIGH){
    LED_Delay *= 2;
  }
  
  digitalWrite(PIN_LED, HIGH);

  delay(LED_Delay);

  digitalWrite(PIN_LED, LOW);

  delay(LED_Delay);
}
