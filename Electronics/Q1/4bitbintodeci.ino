#include <LiquidCrystal.h>
//LCD Initialize
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  // Print a message to the LCD.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Input: ");
  checkinputt();
  convtobin();
  delay(500);
  lcd.clear();
}

//Checks the switch status and converts it to 4 bit binary
void checkinputt()
{
    if(digitalRead(10)==1)
  {
    lcd.print("1");
  }
  else if(digitalRead(10)==0)
  {
	lcd.print("0");
  }
  if(digitalRead(9)==1)
  {
    lcd.print("1");
  }
  else if(digitalRead(9)==0){
	lcd.print("0");
  }
  if(digitalRead(8)==1)
  {
    lcd.print("1");
  }
  else if(digitalRead(8)==0){
	lcd.print("0");
  }
  if(digitalRead(7)==1)
  {
    lcd.print("1");
  }
  else if(digitalRead(7)==0){
	lcd.print("0");
  }

}
//The logic to convert binary to decimal
void convtobin()
{
 int num = 0;
  	if(digitalRead(10)==1)
    {
     num+=8; 
    }
  if(digitalRead(9)==1)
    {
     num+=4; 
    }
  if(digitalRead(8)==1)
    {
     num+=2; 
    }
  if(digitalRead(7)==1)
    {
     num+=1; 
    }
  	lcd.setCursor(0,1);
    lcd.print("Output: ");
	lcd.print(num);
}
