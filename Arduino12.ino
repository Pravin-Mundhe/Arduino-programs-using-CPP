int r=13;  //input digital pin number
int g=5;
//int y=7;
void setup() {
  // put your setup code here, to run once:
pinMode(r, OUTPUT); //to mention which pin number to produce OUTPUT
pinMode(g, OUTPUT);
//pinMode(y, OUTPUT);
Serial.begin(9600);   //9600-to mention frequency value
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(r,HIGH);   //to switch ON LED
delay(3000);
digitalWrite(r,LOW);    //to switch OFF LED
delay(1000);
digitalWrite(g,HIGH);   //to switch ON LED
delay(3000);
digitalWrite(g,LOW);    //to switch OFF LED
delay(1000);
//digitalWrite(y,HIGH);   //to switch ON LED
//delay(3000);
//digitalWrite(y,LOW);    //to switch OFF LED
//delay(3000);
}
