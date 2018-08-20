#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#define Trig 8
#define Echo 9

SoftwareSerial mySerial(2, 3);
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup ()
{
  Serial.begin(9600);
  Serial.println("Hello World!");
  mySerial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  lcd.begin(16, 2);
  lcd.print("    Distance");
}

void loop()
{
  long Duration = 0;
  
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  Duration = pulseIn(Echo, HIGH);

  Duration = Duration / 2.9 / 2 / 10;

  Serial.print("Distance = ");
  Serial.println(Duration);
  delay(300);
  mySerial.write(Duration);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(7, 1);
  lcd.print(Duration);
}



















































#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#define Trig 8
#define Echo 9

SoftwareSerial mySerial(2, 3);
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup ()
{
  Serial.begin(9600);
  Serial.println("Hello World!");
  mySerial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  lcd.begin(16, 2);
  lcd.print("    Distance");
}

void loop()
{
// {
 
//    Serial.write(mySerial.read());
// }

//  if(Serial.available())
//  {
//    mySerial.write(Serial.read());
//  }
   
  // lcd.print("    DISTANCE");

  long Duration = 0;  
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  Duration = pulseIn(Echo, HIGH);

  Duration = Duration / 2.9 / 2 / 10;

  Serial.print("Distance = ");
  Serial.println(Duration);
  delay(300);
  mySerial.write(Duration);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(7, 1);
  lcd.print(Duration);
  //delay(500);

}
