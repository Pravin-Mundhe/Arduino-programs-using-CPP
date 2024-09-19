int led=3;  //input digital pin number
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT); //to mention which pin number to produce OUTPUT
Serial.begin(9600);   //9600-to mention frequency value
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led,HIGH);   //to switch ON LED
delay(1000);
digitalWrite(led,LOW);    //to switch OFF LED
delay(1000);
}
