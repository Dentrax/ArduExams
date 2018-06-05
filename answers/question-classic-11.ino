// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#define PIN_LM35 A0
#define PIN_HEATER 5
#define PIN_COOLER 6

float LM35_Value = 0.0;
float LM35_Volt  = 0.0;
float LM35_TempC = 0.0;
float LM35_TempF = 0.0;

void setup() {
  pinMode(PIN_LM35,   INPUT);
  pinMode(PIN_HEATER, OUTPUT);
  pinMode(PIN_COOLER, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  LM35_Value = analogRead(PIN_LM35);
  LM35_Volt  = (LM35_Value / 1024.0) * 5.0;
  LM35_TempC = (LM35_Volt * 100.0);
  LM35_TempF = (LM35_TempC * 9.0) / 5.0 + 32;
  
  Serial.print("Temp = "); 
  Serial.print(LM35_TempC);
  Serial.print("*C - ");
  Serial.print(LM35_TempF);
  Serial.print("*F");
  Serial.println();
  
  delay(1000);
}
