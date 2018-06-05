// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#define PIN_CAR_IN 4
#define PIN_CAR_OUT 5

int CAR_Status_IN = LOW;
int CAR_Status_OUT = LOW;

void setup() {
  pinMode(PIN_CAR_IN,  INPUT);
  pinMode(PIN_CAR_OUT, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  CAR_Status_IN  = digitalRead(PIN_CAR_IN);
  CAR_Status_OUT = digitalRead(PIN_CAR_OUT);

  if(CAR_Status_IN == HIGH){
    Serial.println("CAR IN");
  }
  
  if(CAR_Status_OUT == HIGH){
    Serial.println("CAR OUT");
  }
  
  delay(100);
}
