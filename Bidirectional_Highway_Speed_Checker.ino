/*   Made by Mohd Aijaj Khan and Ram Singh Tomar
 *    EC 3rd year Electronics Engineering Section "B"
 */


#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sen1=11;
int sen2=12;
unsigned long t1=0;
unsigned long t2=0; 
float velocity;
void setup()
{
  lcd.begin(16, 2);
  pinMode(sen1,INPUT);
  pinMode(sen2,INPUT);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print(" Speed Detector ");
}
void mak_rst(){
  velocity=t2-t1;
  if(velocity<0)
  {
    velocity*=-1;
  }
  velocity=velocity/1000;
  velocity=(5/velocity); //consedering 5 meters here.
  velocity=velocity*3600;//seconds to hour conversion
  velocity=velocity/1000;//meters to kms
  for(int i=1;i<5;++i)
  {
   lcd.setCursor(3,1);
   lcd.print(velocity);
   lcd.print(" Km/hr   ");
   delay(500);
   lcd.setCursor(3,1);
   lcd.print("            ");
   delay(500);
   if(velocity>60)  //threshold for ALERT!
   {
    lcd.setCursor(3,1);
    lcd.print(" ALERT! ");
    delay(500);
    lcd.setCursor(3,1);
   lcd.print("            ");
   
    //lcd.clear();
   }
  }  
}

void loop() 
{ if(digitalRead(sen1)){
 // while(digitalRead(sen1));
  while(digitalRead(sen1)==0);
  t1=millis();
  while(digitalRead(sen2));
  while(digitalRead(sen2)==0);
  t2=millis();
  mak_rst();
  }
  if(digitalRead(sen2)){
  //while(digitalRead(sen2));
  while(digitalRead(sen2)==0);
  t1=millis();
  while(digitalRead(sen1));
  while(digitalRead(sen1)==0);
  t2=millis();
  mak_rst();
  }
  
  
}
