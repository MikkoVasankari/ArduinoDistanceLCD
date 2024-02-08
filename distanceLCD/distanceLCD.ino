#include <HCSR04.h>
#include <LiquidCrystal.h>

byte triggerPin = 2;
byte echoPin = 3;

// LCD_CONTRAST_PIN = 5;
// LCD_BACKLIGHT_PIN = 6;

const int rs = 7, en = 8, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup () {
  Serial.begin(9600);
  HCSR04.begin(triggerPin, echoPin);

  analogWrite(5, 10);
  analogWrite(6, 50);
  lcd.begin(16, 2);

  // 1st Line
  lcd.setCursor(0, 0);
  lcd.print("hello world");

  // 2nd Line
  //lcd.setCursor(0, 1);
  //lcd.print("hello world");
}

void loop () {
  double* distances = HCSR04.measureDistanceCm();

  Serial.print("1: ");
  Serial.print(distances[0]);
  Serial.println(" cm");

  Serial.println("---");

  lcd.setCursor(0, 1);
  lcd.print(distances[0]);
  lcd.print(" cm");
  delay(1000);
}
