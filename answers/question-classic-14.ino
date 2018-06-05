// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#include <LiquidCrystal.h>
 
LiquidCrystal lcd(0, 1, 4, 5, 6, 7);

#define PIN_HCSR04_TRIG 8
#define PIN_HCSR04_ECHO 9

float HCSR04_Duration = 0.0;
float HCSR04_Distance = 0.0;

void setup() {
  pinMode(PIN_HCSR04_TRIG, OUTPUT);
  pinMode(PIN_HCSR04_ECHO, INPUT);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WAIT...");
  
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0,0);
  
  digitalWrite(PIN_HCSR04_TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(PIN_HCSR04_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_HCSR04_TRIG, LOW);

  HCSR04_Duration = pulseIn(PIN_HCSR04_ECHO, HIGH);
  HCSR04_Distance = (HCSR04_Duration / 2) / 29.1;

  if (HCSR04_Distance >= 200 || HCSR04_Distance <= 0){
    lcd.print("OUT OF RANGE");
    Serial.println("Out of range");
  } else {
    if(HCSR04_Distance > 0 && HCSR04_Distance <= 15){
      lcd.print("TOO CLOSE");
    } else if(HCSR04_Distance > 15 && HCSR04_Distance <= 30){
      lcd.print("CLOSE");
    } else if(HCSR04_Distance > 30 && HCSR04_Distance <= 40){
      lcd.print("FAR");
    } else if(HCSR04_Distance > 40 && HCSR04_Distance <= 60){
      lcd.print("TOO FAR");
    }
    
    Serial.print("Distance = ");
    Serial.print(HCSR04_Distance);
    Serial.print(" cm");
    Serial.println();
  }
  
  delay(1000);
}
