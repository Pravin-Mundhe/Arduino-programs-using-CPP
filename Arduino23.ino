
int fir=A0;

void setup() {
  // put your setup code here, to run once:
pinMode(fir, INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int i=analogRead(ldr);

delay(800);
if(i>=300)
{
  Serial.println(i);
  Serial.println("Fire Detected");
  delay(800);
}
else
{
  Serial.println(i);
  Serial.println("Fire Not Detected");
  delay(800);
}
}
