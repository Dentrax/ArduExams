// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#include <LiquidCrystal.h>

#define BTN_LCD_RIGHT   0
#define BTN_LCD_UP      1
#define BTN_LCD_DOWN    2
#define BTN_LCD_LEFT    3
#define BTN_LCD_SELECT  4
#define BTN_LCD_NONE    5

LiquidCrystal lcd(0, 1, 4, 5, 6, 7);

int LCD_KeyValue = 0;
int LCD_KeyIn    = 0;

int ScorePlayer1 = 0;
int ScorePlayer2 = 0;

int CurrentDicePlayer1 = 0;
int CurrentDicePlayer2 = 0;

bool IsPlayer1Diced = false;
bool IsPlayer2Diced = false;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("P1 Score:");
  lcd.setCursor(0, 2);
  lcd.print("P2 Score:");
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(10, 1);
  lcd.print(ScorePlayer1); 
  lcd.setCursor(10, 2);
  lcd.print(ScorePlayer2);
  
  LCD_KeyValue = readLCDButtons();

  if(LCD_KeyValue == BTN_LCD_LEFT && !IsPlayer1Diced && !IsPlayer2Diced){
    IsPlayer1Diced = true;
    CurrentDicePlayer1 = random(1, 6);
    lcd.setCursor(14, 1);
    lcd.print(CurrentDicePlayer1);
  }
  
  if(LCD_KeyValue == BTN_LCD_RIGHT && IsPlayer1Diced && !IsPlayer2Diced){
    IsPlayer2Diced = true;
    CurrentDicePlayer2 = random(1, 6);
    lcd.setCursor(14, 2);
    lcd.print(CurrentDicePlayer2);
  }

  if(IsPlayer1Diced && IsPlayer2Diced){
    if (CurrentDicePlayer1 > CurrentDicePlayer2){
      ScorePlayer1++;
    } else if (CurrentDicePlayer1 < CurrentDicePlayer2){
      ScorePlayer2++;
    }
    resetTurn();
  }
  
  
  delay(1000);
}

void resetTurn(){
  IsPlayer1Diced = false;
  IsPlayer2Diced = false;
  CurrentDicePlayer1 = 0;
  CurrentDicePlayer2 = 0;
}

int readLCDButtons(){
 LCD_KeyIn = analogRead(0);   
 if (LCD_KeyIn > 1000) return BTN_LCD_NONE; 
 if (LCD_KeyIn < 50)   return BTN_LCD_RIGHT; 
 if (LCD_KeyIn < 195)  return BTN_LCD_UP;
 if (LCD_KeyIn < 380)  return BTN_LCD_DOWN;
 if (LCD_KeyIn < 555)  return BTN_LCD_LEFT;
 if (LCD_KeyIn < 790)  return BTN_LCD_SELECT;  
 return BTN_LCD_NONE;  
}
