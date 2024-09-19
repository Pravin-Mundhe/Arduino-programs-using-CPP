#include <ESP8266WiFi.h>
#include <PubSubClient.h>

int val1,val2;
String data,data1;

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


void setup_wifi() 
 {
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
   Serial.print("Receving message:");
     Serial.println(message);
//     Serial.println();
  }
  
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.subscribe("123");
    } 
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
   }
 }

void setup() {
//    pinMode(D4,OUTPUT);
    Serial.begin(9600);
    setup_wifi();
    client.setServer(mqtt_server, 1883);
 }

void loop() {
  
   val1 = random(0,50);
   val2 =random(50,100);

   data = "value1:"+String(val1)+" "+"value2:"+String(val2);
   data1 = "value1:"+String("100")+" "+"value2:"+String("200");
   
   client.setCallback(callback);
    if (!client.connected()) {
    reconnect();
  }
    client.loop();
    data.toCharArray(val,sizeof(val));
    ++value;
    snprintf (msg, 50,val, value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("iot", msg);

    if(message == "a"){
      Serial.println("hello");
    }
    
    delay(1000);
    message ="";
}
