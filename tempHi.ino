#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#define DHTPIN 7
#define DHTTYPE DHT11
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht (7, 11);
int pine = 4;
 
void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
  pinMode(pine, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT);
  }
 
void loop(){
  delay(10000);
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("`C");
  
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print("%");
  if (h < 45){
  digitalWrite(pine, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(5, HIGH);
  }
  else{
  digitalWrite(pine, LOW);
  digitalWrite(8, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(10, HIGH);
  }
}
