int gas=A0;
int led=D0;
void setup() {
  // put your setup code here, to run once:
pinMode(gas, INPUT);
pinMode(led, OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int d=analogRead(gas);
Serial.println(d); 
delay(100);
if(d>=650)
{
 Serial.println("Gas Detected");  
 digitalWrite(led,HIGH); 
 delay(500); 
}
else
{
 Serial.println("Gas Not Detected"); 
digitalWrite(led,LOW);
 delay(500);
}
}
