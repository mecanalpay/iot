#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "BizimWifiAdi";
const char* password = "Sifresi";

ESP8266WebServer server(80);

#define LED     D0

void handleLed() {
    if (server.arg(0)=="ON") digitalWrite(LED, LOW);
    else digitalWrite(LED, HIGH);
  
    String message = "<!DOCTYPE HTML>\r\n<html>";
     message +="<h3>ESP8266 NodeMCU Arduino Web Sunucu</h3>";
     message += "<p>GPIO0 (LED D0) <a href=\"led?pin=ON\">";
     message += "<button>A&Ccedil</button></a>&nbsp;";
     message += "<a href=\"led?pin=OFF\"><button>";
     message += "KAPAT</button></a></p></html>";
     server.send(200, "text/html", message);
}

void handleNotFound(){
  String message = "404 File Not Found\n\n";
  server.send(404, "text/plain", message);
}

void setup(void){
  pinMode(LED, OUTPUT); digitalWrite(LED, HIGH); 
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  
  Serial.print("IP adresi : ");
  Serial.println(WiFi.localIP());
  
  server.on("/led", handleLed);
  
  server.on("/", [](){
   String message = "<!DOCTYPE HTML>\r\n<html>";
   message +="<h3>ESP8266 Arduino Web Sunucu</h3>";
   message += "<a href=/led>Led Ornek</a></html>";
   server.send(200, "text/html", message);
 });
     
     server.onNotFound(handleNotFound);
     server.begin();
}

void loop(void){
  server.handleClient();
}
