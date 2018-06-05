// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ==================================================== 

#define PIN_HCSR04_TRIG 8
#define PIN_HCSR04_ECHO 9

#define PIN_LED1 4
#define PIN_LED2 5
#define PIN_LED3 6
#define PIN_LED4 7

float HCSR04_Duration = 0.0;
float HCSR04_Distance = 0.0;

void setup() {
  pinMode(PIN_HCSR04_TRIG, OUTPUT);
  pinMode(PIN_HCSR04_ECHO, INPUT);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_LED4, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(PIN_HCSR04_TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(PIN_HCSR04_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_HCSR04_TRIG, LOW);

  HCSR04_Duration = pulseIn(PIN_HCSR04_ECHO, HIGH);
  HCSR04_Distance = (HCSR04_Duration / 2) / 29.1;

  if (HCSR04_Distance >= 200 || HCSR04_Distance <= 0){
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_LED4, LOW);
    Serial.println("Out of range");
  } else {
    if(HCSR04_Distance > 0 && HCSR04_Distance <= 15){
      digitalWrite(PIN_LED1, HIGH);
      digitalWrite(PIN_LED2, HIGH);
      digitalWrite(PIN_LED3, HIGH);
      digitalWrite(PIN_LED4, HIGH);
    } else if(HCSR04_Distance > 15 && HCSR04_Distance <= 30){
      digitalWrite(PIN_LED1, HIGH);
      digitalWrite(PIN_LED2, HIGH);
      digitalWrite(PIN_LED3, HIGH);
      digitalWrite(PIN_LED4, LOW);
    } else if(HCSR04_Distance > 30 && HCSR04_Distance <= 40){
      digitalWrite(PIN_LED1, HIGH);
      digitalWrite(PIN_LED2, HIGH);
      digitalWrite(PIN_LED3, LOW);
      digitalWrite(PIN_LED4, LOW);
    } else if(HCSR04_Distance > 40 && HCSR04_Distance <= 60){
      digitalWrite(PIN_LED1, HIGH);
      digitalWrite(PIN_LED2, LOW);
      digitalWrite(PIN_LED3, LOW);
      digitalWrite(PIN_LED4, LOW);
    }
    
    Serial.print("Distance = ");
    Serial.print(HCSR04_Distance);
    Serial.print(" cm");
    Serial.println();
  }
  
  delay(1000);
}
