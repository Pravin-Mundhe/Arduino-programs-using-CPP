int g=3;
int sw=5;
int s=1;
void setup() {
  // put your setup code here, to run once:
pinMode(g, OUTPUT); //to mention which pin number to produce OUTPUT
pinMode(sw, INPUT);

Serial.begin(9600);   //9600-to mention frequency value
}

void loop() {
  // put your main code here, to run repeatedly:
int s=digitalRead(sw);
if(s==0)
{
  digitalWrite(g,HIGH);  
  Serial.print("ON");
  delay(500); 
}
else
{
  digitalWrite(g,LOW); 
  Serial.print("OFF"); 
  delay(500);
}
}
