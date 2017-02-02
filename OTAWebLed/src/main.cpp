#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#define LED     D0
const char* ssid = "BizimWifi";
const char* password = "sifresi";
ESP8266WebServer server(80);
void setup() {
 pinMode(LED, OUTPUT); digitalWrite(LED, HIGH); 
  Serial.begin(115200); Serial.println("Booting");
  WiFi.mode(WIFI_STA); WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000); ESP.restart(); }
  //ArduinoOTA.setPort(8266);
  //ArduinoOTA.setHostname("myesp8266");
  //ArduinoOTA.setPassword("admin");
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) type = "sketch";
    else type = "filesystem";
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd"); });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin(); Serial.println("Ready");
  Serial.print("IP address: "); Serial.println(WiFi.localIP());

  server.on("/", [](){
    if (server.arg(0)=="ON") digitalWrite(LED, LOW);
    else digitalWrite(LED, HIGH);
    String message = "<!DOCTYPE HTML>\r\n<html>";
     message +="<h3>ESP8266 OTA Web Sunucu Deneme</h3>";
     message += "<p>GPIO0 (LED D0) <a href=\"?pin=ON\">";
     message += "<button>A&Ccedil</button></a>&nbsp;";
     message += "<a href=\"?pin=OFF\"><button>";
     message += "KAPAT</button></a></p></html>";
     server.send(200, "text/html", message);
  });
  server.begin();
}

void loop() {
  ArduinoOTA.handle(); server.handleClient(); }
