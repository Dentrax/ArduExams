// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#define PIN_LED1  15
#define PIN_LED2  16

int LED_Random = 0;

void setup() {
  pinMode(PIN_LED1,   OUTPUT);
  pinMode(PIN_LED2,   OUTPUT);

  randomSeed(analogRead(0));
  
  Serial.begin(9600);
}

void loop() {
  LED_Random = random(10, 50);

  if(LED_Random % 2 == 0){
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, HIGH);
  } else {
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, LOW);
  }

  delay(1000);
}
