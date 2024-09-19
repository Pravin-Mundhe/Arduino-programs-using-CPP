int g=3;
int r=5;
int sw1=7;
int sw2=9;
int s1=0;
int s2=0;
void setup() {
  // put your setup code here, to run once:
pinMode(g, OUTPUT); //to mention which pin number to produce OUTPUT
pinMode(r, OUTPUT);
pinMode(sw1, INPUT);
pinMode(sw2, INPUT);

Serial.begin(9600);   //9600-to mention frequency value
}

void loop() {
  // put your main code here, to run repeatedly:
int s1=digitalRead(sw1);
int s2=digitalRead(sw2);

if(s1==1)
{
  digitalWrite(g,HIGH);  
  Serial.print("GREEN");
  delay(500); 
}
else if(s2==1)
{
  digitalWrite(r,HIGH);  
  Serial.print("RED");
  delay(500); 
}
else if((s1==1) && (s2==1))
{
  digitalWrite(g,HIGH);  
  digitalWrite(r,HIGH);  
  Serial.print("GGRR");
  delay(500); 
}
else
{
  digitalWrite(g,LOW); 
  digitalWrite(r,LOW); 
  Serial.print("OFF"); 
  delay(500);
}
}
