int bz=D5;
void setup() {
  // put your setup code here, to run once:
pinMode(bz, OUTPUT); //to mention which pin number to produce OUTPUT
Serial.begin(115200);   
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(bz,HIGH);
delay(1000);

digitalWrite(bz,LOW);
}
