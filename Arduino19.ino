int ir1=D4;
void setup() {
  // put your setup code here, to run once:
pinMode(D4, INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int ir=digitalRead(ir1);
Serial.print(ir);
delay(500);
if(ir==1)
{
 Serial.println("Sensor Detected"); 
 delay(500);
}
else
{
 Serial.println("Sensor Not Detected"); 
 delay(500);
}
}
