#include <ESP8266WiFi.h>
#include <PubSubClient.h>


const char* ssid = "BizimWifi";
const char* password = "abc12345";

const char* mqtt_server = "iot.eclipse.org";
//const char* mqtt_server = "broker.mqttdashboard.com";
const char* clientID = "NodeMCUDevKit";
const char* outTopic = "ab2017/mesaj";

int ldr;

unsigned long previousMillis = 0;        
const long interval = 2000;              
 
WiFiClient espClient; PubSubClient client(espClient);
char msg[50];

void setup_wifi() {
  delay(10); Serial.println();
  Serial.print("Connecting to "); Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print("."); }
  Serial.println(""); Serial.println("WiFi connected");
  Serial.println("IP address: ");  Serial.println(WiFi.localIP());
}


void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    #if (client.connect(clientID,"user","pass")) {
    if (client.connect(clientID)) {
      Serial.println("connected"); client.publish(outTopic, clientID);
    } else {
      Serial.print("failed, rc="); Serial.print(client.state());
      Serial.println(" try again in 5 seconds"); delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);

}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
   client.loop();
   ldr=analogRead(A0);
   Serial.println(ldr);
   dtostrf(ldr , 2, 2, msg);
   client.publish(outTopic, msg);
   delay(5000);
}



