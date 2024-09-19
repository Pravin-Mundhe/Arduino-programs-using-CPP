#include <ESP8266WiFi.h>
const char* ssid = "B-504";
const char* password = "gitam123";

int ledPin = D3;// GPIO12 D6
int led2=D5;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, LOW);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  //Serial.println("/");

}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Match the request
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1) {
    digitalWrite(ledPin, LOW);
    value = LOW;
  }
  int v = LOW;
  if (request.indexOf("/LED2=ON") != -1) {
    digitalWrite(led2, HIGH);
    v = HIGH;
  }
  if (request.indexOf("/LED2=OFF") != -1) {
    digitalWrite(led2, LOW);
    v = LOW;
  }

  // Set ledPin according to the request
  //digitalWrite(ledPin, value);

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); // do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.println("Led pin is now: ");
if (value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"><button>ON</button></a>&nbsp;<a href=\"/LED=OFF\"><button>OFF</button></a></p>");
  client.println("<br><br>");
  client.println("Led pin is now: ");
  if (v == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
   
  
  
  client.println("<a href=\"/LED2=ON\"><button>ON</button></a>&nbsp;<a href=\"/LED2=OFF\"><button>OFF</button></a></p>");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
