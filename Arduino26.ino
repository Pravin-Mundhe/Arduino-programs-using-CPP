int wet=3;
int dry=2;
int sensor=A0; //soil sensor input at analog
int v=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(wet, OUTPUT);
pinMode(dry, OUTPUT);
delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Moisture level"); 
int v=analogRead(sensor);
v=v/10;
Serial.println(v); 
if(v>50)
{
  Serial.println("Wet"); 
  digitalWrite(wet,HIGH); 
  delay(100);
}
else
{
  Serial.println("Dry"); 
  digitalWrite(dry,HIGH);
  delay(100);
}
delay(100);
digitalWrite(wet,LOW); 
digitalWrite(dry,LOW); 
}
