// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================
 
#define PIN_BUTTON1 2
#define PIN_BUTTON2 3

int A1_Data = 0;
int A2_Data = 0;

void setup() {
  pinMode(PIN_BUTTON1, INPUT_PULLUP);
  pinMode(PIN_BUTTON2, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(PIN_BUTTON1) == HIGH){
    A1_Data = analogRead(A1);
    Serial.println(A1_Data);
  } else if (digitalRead(PIN_BUTTON2) == HIGH){
    A2_Data = analogRead(A2);
    Serial.println(A2_Data);
  }
  
  delay(100);
}
