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

int LCD_CurrentX = 0;
int LCD_CurrentY = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  
  lcd.setCursor(1,1);
  lcd.print("A");

  Serial.begin(9600);
}

void loop() {
  LCD_CurrentX = constrain(LCD_CurrentX, 0, 16);
  LCD_CurrentY = constrain(LCD_CurrentY, 0, 2);
  
  lcd.clear();
  lcd.setCursor(LCD_CurrentX, LCD_CurrentY);
  lcd.print("A");
  
  LCD_KeyValue = readLCDButtons();

  switch(LCD_KeyValue){
    case BTN_LCD_UP:
      LCD_CurrentY++;
      break;
    case BTN_LCD_DOWN:
      LCD_CurrentY--;
      break; 
    case BTN_LCD_LEFT:
      LCD_CurrentX--;
      break;   
    case BTN_LCD_RIGHT:
      LCD_CurrentX++;
      break;
    
  }
  
  delay(10);
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
