#include <ESP8266WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);
const char* ssid = "B-504";
const char* password = "gitam123";
const char* mqtt_server = "broker.mqtt-dashboard.com";  

long lastMsg = 0;
char msg[50];
int value = 0;
String message="";
char val[50];


void setup_wifi() {

  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
  
  void callback(char* topic, byte* payload, unsigned int length) {
      for (int i = 0; i < length; i++) {
        message=message+(char)payload[i];
        }
      Serial.println(message);
//      Serial.println();
  }
  
void reconnect() {
  while (!client.connected()) {
      Serial.print("Attempting MQTT connection...");
      String clientId = "ESP8266Client-";
      clientId += String(random(0xffff), HEX);
      if (client.connect(clientId.c_str())) {
        Serial.println("connected");
        client.subscribe("pravin");
      } 
      else {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
        delay(500);
      }
  }
}

void setup() {
    pinMode(D3,OUTPUT); //light 
    pinMode(D4,OUTPUT); //Fan
    Serial.begin(115200);
    setup_wifi();
    client.setServer(mqtt_server, 1883);
 }

void loop() {

     client.setCallback(callback);
    if (!client.connected()) {
      reconnect();
    }
    client.loop();
         if(message == "a")
         {
          digitalWrite(D3,HIGH);
          Serial.println("light on");
         }
         else if(message == "b")
         {
          digitalWrite(D3,LOW);
          Serial.println("light off");
         }
         else if(message == "c")
         {
          digitalWrite(D4,HIGH);
          Serial.println("fan on");
         }
         else if(message == "c")
         {
          digitalWrite(D4,LOW);
          Serial.println("fan off");
         }
//        delay(1000);
        message = "";
       
}
