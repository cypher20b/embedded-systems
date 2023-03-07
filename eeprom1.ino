
#include <EEPROM.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
char message;
int memory_location = 0;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
lcd.print("ok let us see");
pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(3) == HIGH){
memory_location++;
//message = "who are you";
EEPROM.write(memory_location, ' ');

  }
lcd.print(memory_location);
}
