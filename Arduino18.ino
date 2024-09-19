const int gas=A0;
int ival=0
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);   
}

void loop() {
  // put your main code here, to run repeatedly:
ival=analogRead(gas);
Serial.print("Gas value is: ");
Serial.print(ival);
delay(500);
}
