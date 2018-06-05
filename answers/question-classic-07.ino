// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#define PIN_READ A2

#define PIN_LED1 4
#define PIN_LED2 5
#define PIN_LED3 6

int READ_Data = 0;

void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  READ_Data = analogRead(PIN_READ);
  Serial.println(READ_Data);
  
  if(READ_Data > 0 && READ_Data <= 20){
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
  } else if(READ_Data > 20 && READ_Data <= 40){
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, LOW);
  } else if(READ_Data > 40 && READ_Data <= 60){
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, HIGH);
  } else {
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
  }
  
  delay(1000);
}
