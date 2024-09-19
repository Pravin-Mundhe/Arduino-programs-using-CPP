#include<SoftwareSerial.h>
SoftwareSerial BT(0,1);
String readvoice;
char c;
int led= 6;


void setup() 
{
  Serial.begin(9600);
  //Declaring motor pin as output
  pinMode(led, OUTPUT);
  Serial.println("Welcome user");
  Serial.println("waiting for your command");
}
void loop()
{
  while (Serial.available()>0)
  {
    c = Serial.read();
  Serial.println(c);
  if(c =='a')
  {
    
    digitalWrite(led,HIGH);
    Serial.println("led on");
  }

   else if(c =='b')
  {
    digitalWrite(led,LOW);
    Serial.println("led off");
  }
  }
}
