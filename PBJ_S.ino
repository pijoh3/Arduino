#include <SoftwareSerial.h>

#define buttonpin 7
#define motor 8
#define TX 9
#define RX 10
#define lpin 2

SoftwareSerial mySerial(TX, RX);
boolean buttonstate = 0;
long data;

void setup() {
pinMode(buttonpin, INPUT_PULLUP);
pinMode(motor, OUTPUT);
pinMode(lpin, OUTPUT);
Serial.begin(9600);
mySerial.begin(9600);
Serial.println("Hello");
attachInterrupt(0, sstop, RISING);
}

void loop() {  
delay(330);
data = mySerial.read();
Serial.println(data);

if (digitalRead(buttonpin) == 0)
{
  if ((buttonstate == 0) && (data < 30))
  {
    digitalWrite(motor, HIGH);
  }
  else if (buttonstate == 1)
  {
    digitalWrite(motor, LOW);
  }

  buttonstate = !buttonstate;  
}

if ((data < 10) && (data >= 0))
{
  digitalWrite(lpin, HIGH);
  delay(10);
  digitalWrite(lpin, LOW);
}

if ((data > 10) && (data < 30) && (buttonstate == 1))
{
  digitalWrite(motor, HIGH);
}

if (data >= 30)
{
  digitalWrite(motor, LOW);
  buttonstate = !buttonstate;
}
}

void sstop() {
digitalWrite(motor, LOW);
}
