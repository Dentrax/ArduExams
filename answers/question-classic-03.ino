// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#define PIN_BUTTON 5
 
#define PIN_LED1  14
#define PIN_LED2  15
#define PIN_LED3  16
#define PIN_LED4  17
#define PIN_LED5  18

int LED_CAR_Data = 0; //0-RED, 1-YELLOW, 2-GREEN

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED1,   OUTPUT);
  pinMode(PIN_LED2,   OUTPUT);
  pinMode(PIN_LED3,   OUTPUT);
  pinMode(PIN_LED4,   OUTPUT);
  pinMode(PIN_LED5,   OUTPUT);

  randomSeed(analogRead(0));
  
  Serial.begin(9600);
}

void turnOnLED(int led){
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
  digitalWrite(PIN_LED3, LOW);
  digitalWrite(PIN_LED4, LOW);
  digitalWrite(PIN_LED5, LOW);

  if(led == 1){
    digitalWrite(PIN_LED1, HIGH);
  } else if(led == 2){
    digitalWrite(PIN_LED2, HIGH);
  } else if(led == 3){
    digitalWrite(PIN_LED3, HIGH);
  } else if(led == 4){
    digitalWrite(PIN_LED4, HIGH);
  } else if(led == 5){
    digitalWrite(PIN_LED5, HIGH);
  }
}

void loop() {
  if(digitalRead(PIN_BUTTON) == HIGH){
    turnOnLED(random(1, 5 + 1));
  }

}
