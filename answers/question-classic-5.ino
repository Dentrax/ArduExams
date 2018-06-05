// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#define PIN_LED_CAR_RED    13
#define PIN_LED_CAR_YELLOW 14
#define PIN_LED_CAR_GREEN  15

#define PIN_LED_PEDESTRIAN_RED    20
#define PIN_LED_PEDESTRIAN_GREEN  21

int LED_CAR_Data        = 0; //0-RED, 1-YELLOW, 2-GREEN
int LED_PEDESTRIAN_Data = 0; //0-RED, 1-GREEN

void setup() {
  pinMode(PIN_LED_CAR_RED,    OUTPUT);
  pinMode(PIN_LED_CAR_YELLOW, OUTPUT);
  pinMode(PIN_LED_CAR_GREEN,  OUTPUT);

  pinMode(PIN_LED_PEDESTRIAN_RED,   OUTPUT);
  pinMode(PIN_LED_PEDESTRIAN_GREEN, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(PIN_LED_CAR_RED,    HIGH);
  digitalWrite(PIN_LED_CAR_YELLOW, LOW);
  digitalWrite(PIN_LED_CAR_GREEN,  LOW);
  LED_CAR_Data = 0;
  Serial.println(LED_CAR_Data);

  digitalWrite(PIN_LED_PEDESTRIAN_RED,   LOW);
  digitalWrite(PIN_LED_PEDESTRIAN_GREEN, HIGH);
  LED_PEDESTRIAN_Data = 1;
  Serial.println(LED_PEDESTRIAN_Data);
  
  delay(5000);

  digitalWrite(PIN_LED_CAR_RED,    LOW);
  digitalWrite(PIN_LED_CAR_YELLOW, HIGH);
  digitalWrite(PIN_LED_CAR_GREEN,  LOW);
  LED_CAR_Data = 1;
  Serial.println(LED_CAR_Data);

  digitalWrite(PIN_LED_PEDESTRIAN_RED,   HIGH);
  digitalWrite(PIN_LED_PEDESTRIAN_GREEN, LOW);
  LED_PEDESTRIAN_Data = 0;
  Serial.println(LED_PEDESTRIAN_Data);
  
  delay(1000);

  digitalWrite(PIN_LED_CAR_RED,    LOW);
  digitalWrite(PIN_LED_CAR_YELLOW, LOW);
  digitalWrite(PIN_LED_CAR_GREEN,  HIGH);
  LED_CAR_Data = 2;
  Serial.println(LED_CAR_Data);
  
  delay(3000);
}
