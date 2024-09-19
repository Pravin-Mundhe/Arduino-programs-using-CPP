int ldr=D0;
int led=D3;
void setup() {
  // put your setup code here, to run once:
pinMode(ldr, INPUT);
pinMode(led, OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int i=analogRead(ldr);
if(i==0)
{
  Serial.println(i);
  Serial.println("Day Time");
  digitalWrite(led,LOW);
  delay(100);
}
else
{
  Serial.println(i);
  Serial.println("Night Time");  
  digitalWrite(led,HIGH);
  delay(100);
}
}
