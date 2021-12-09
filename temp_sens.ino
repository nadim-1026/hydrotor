#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int val;
int tempPin=A0;
int led=8;
int motor=7;

void setup() {
  lcd.begin(16,2);
 Serial.begin(9600);
 pinMode(8,OUTPUT);
 digitalWrite(8,LOW);
 pinMode(7,OUTPUT);
 digitalWrite(8,LOW);
 
 lcd.setCursor(0,0);
 lcd.print("TEMPERATURE CONTROLLED");
 lcd.setCursor(0,2);
 lcd.print("SYSTEM");
 delay(1000);
 lcd.clear();
 

}

void loop() {
  val= analogRead(tempPin);
  float mv=(val/1024.0)*5000;
  float cel=mv/10;
  lcd.setCursor(0,0);
  lcd.print("TEMPERATURE=");
  lcd.print(cel);
  lcd.setCursor(0,2);
  lcd.print("*C");
  delay(1000);

  if( cel>=70)
  {
    digitalWrite(8,HIGH);
    lcd.print("WARNING  ");
    digitalWrite(7,HIGH);
  }
  else
   {  digitalWrite(8,LOW);
      digitalWrite(7,LOW);
  
   

  }

  
 
 

}
