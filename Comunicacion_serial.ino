#include <LiquidCrystal.h>

char frase;

LiquidCrystal lcd(22, 23, 5, 18, 19, 21);  //Pines del LCD - ESP32

void setup() {
  Serial.begin(115200); //Monitor Serie
  lcd.begin(16,2);      //Tallaño de LCD 16 col, 2 lin.
}

void loop() {
  if (Serial.available()){
    delay(50);
    lcd.clear();
    while (Serial.available()>0) {
      frase = Serial.read();
      lcd.print(frase);
    }
  }
}
