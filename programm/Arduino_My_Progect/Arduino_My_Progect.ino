const int Button1 = 3;
const int Button2 = 4;
const int Button3 = 5;
const int ZUMMER = 2;
const int LED1 = 6;
const int LED2 = 7;
const int LED3 = 8;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() { 
  lcd.init();
  lcd.backlight();
   pinMode(ZUMMER, INPUT);
   pinMode(Button1, OUTPUT);
   pinMode(Button2, OUTPUT);
   pinMode(Button3, OUTPUT);
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
}

void loop() {
  if (digitalRead(Button1) == HIGH){
    noTone(ZUMMER);
    lcd.setCursor(0,0);
    lcd.print("Danger"); lcd.clear();
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

  }
    
  else if(digitalRead(Button2) == HIGH){
    tone(ZUMMER, 200);
    lcd.setCursor(0, 7);
    lcd.print("Anxiety!"); lcd.clear();
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
 }
  
  else if (digitalRead(Button3) == HIGH){
    noTone(ZUMMER);
    lcd.setCursor(2, 0);
    lcd.print("We have good");
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
  }



}
