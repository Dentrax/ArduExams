// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#define PIN_LDR A3

#define PIN_LED1 4
#define PIN_LED2 5
#define PIN_LED3 6

float LDR_Value = 0.0;

void setup() {
  pinMode(PIN_LDR,  INPUT);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  LDR_Value = analogRead(PIN_LDR);

  if (LDR_Value > 800){ 
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
  } else if (LDR_Value > 600){
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
  } else if (LDR_Value > 400){
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, LOW);
  } else if (LDR_Value > 200){
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, HIGH);
  }

  Serial.print("Light Intensity = ");
  Serial.print(LDR_Value);
  Serial.println();
  
  delay(1000);
}
