int ir1=D4;
int led=D6;
int c=0;
void setup() {
  // put your setup code here, to run once:
pinMode(ir1, INPUT);
pinMode(led, OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int ir=digitalRead(ir1);
Serial.print(ir);
delay(500);
if(ir==0)
{
 Serial.println("Sensor Detected"); 
 c=c+1;
 Serial.println(c); 
 if(c>=5)
 {
  digitalWrite(led,HIGH);
 }
 delay(500);
 
}
else
{
 Serial.println("Sensor Not Detected"); 
 digitalWrite(led,LOW);
 delay(500);
}
}