// ====================================================
// ArduExams Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#include <LiquidCrystal.h>
#include <DHT.h>
//https://github.com/adafruit/DHT-sensor-library
//Library Manager -> Adafruit_Sensor

#define PIN_DHT11 8
#define DHTTYPE DHT11

DHT dht(PIN_DHT11, DHTTYPE);

LiquidCrystal lcd(0, 1, 4, 5, 6, 7);

float DHT11_Humidity = 0.0;
float DHT11_Temperature = 0.0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WAIT...");
  
  dht.begin();
  
  lcd.print("Temp:  Humidity:");
  
  Serial.begin(9600);
}

void loop() {
  DHT11_Humidity = dht.readHumidity();
  DHT11_Temperature = dht.readTemperature(true);

  if(isnan(DHT11_Humidity) || isnan(DHT11_Temperature)){
    lcd.print("NaN");
    Serial.println("NaN");
  } else {   
    lcd.setCursor(0, 1);
    
    if(DHT11_Humidity > 70){
      lcd.print("MORE MOISTURE");
    } else if (DHT11_Humidity >= 50 && DHT11_Humidity <= 70){
      lcd.print("MOISTURE");
    } else if (DHT11_Humidity < 50){
      lcd.print("");
    }
    
    lcd.setCursor(7,1);
    
    if(DHT11_Temperature > 25){
      lcd.print("HOT");
    } else if (DHT11_Humidity < 15){
      lcd.print("COLD");
    }
  }
  
  delay(1000);
}
