int gas=A0;
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
WiFiClient client;

const char* MY_SSID = "B-504";
const char* MY_PWD = "gitam123";
const char* TS_SERVER = "api.thingspeak.com";
String TS_API_KEY = "T5POAK2MWXOGWIUJ";
//WiFiClientSecure client;

/*
   Connecting WiFi
 **/
void connectWifi()
{
  Serial.print("Connecting to " + *MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("");
}
void setup() {
  // put your setup code here, to run once:
pinMode(gas,INPUT);
Serial.begin(115200);
  connectWifi();
}

void loop() {
  // put your main code here, to run repeatedly:
int c=analogRead(gas);
Serial.print(c);
 if (client.connect(TS_SERVER, 80))
  {
    String postStr = TS_API_KEY;
    postStr += "&field1=";
    postStr += String(c);
    postStr += "\r\n\r\n";
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + TS_API_KEY + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
    delay(1000);
  client.stop();
}
}
