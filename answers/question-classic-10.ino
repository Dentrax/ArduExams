// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#define PIN_DATA A5
#define PIN_BUTTON 2

int DATA_Array[5] = {0, 0, 0, 0, 0};

int DATA_Counter = 0;

int DATA_Value = 0;
int BUTTON_State = LOW;
int BUTTON_State_Last = LOW;

void setup() {
  pinMode(PIN_DATA,   INPUT);
  pinMode(PIN_BUTTON, INPUT);
  
  Serial.begin(9600);
}

void printLast5DataToSerial(){
   for (int i = 0; i < 5; i++){
      Serial.print(DATA_Array[i]);
      Serial.print(";");
   }
   Serial.println();
}

void loop() { 
  BUTTON_State = digitalRead(PIN_BUTTON);
  DATA_Value = analogRead(PIN_DATA);

  DATA_Array[0] = DATA_Array[1];
  DATA_Array[1] = DATA_Array[2];
  DATA_Array[2] = DATA_Array[3];
  DATA_Array[3] = DATA_Array[4];
  
  if(DATA_Counter != 4){
    DATA_Array[DATA_Counter] = DATA_Value;
    DATA_Array[4] = 0;
    DATA_Counter++;
  } else {
    DATA_Array[DATA_Counter] = DATA_Value;
  }
  
  if(BUTTON_State && !BUTTON_State_Last){
    printLast5DataToSerial();
    delay(100);
  }
  
  BUTTON_State_Last = BUTTON_State;

  delay(1000);
}
