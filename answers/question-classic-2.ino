// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#define PIN_BUTTON 14
 
int BUTTON_Status = 0; //0-INIT, 1-FIRST-PRESS,

void setup() {
  pinMode(PIN_BUTTON, INPUT);

  Serial.begin(9600);
}

void loop() {
  if(BUTTON_Status == 0 && digitalRead(PIN_BUTTON) == HIGH){
    BUTTON_Status = 1;
    delay(5000);

    while(true){
      Serial.println(readSensorData());
    }
  }
  
  delay(1000);
}

int readSensorData(){
  return 0; //Test only
}  
 
