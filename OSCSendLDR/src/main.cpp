#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>

char ssid[] = "BizimWifi";    
char pass[] = "sifresi";   
int ldr;
int xdata=0;
WiFiUDP Udp;    
const IPAddress outIp(192,168,1,62);      
const unsigned int outPort = 9000;     
const unsigned int localPort = 8888;
void setup() {
    Serial.begin(115200);
    Serial.print("Baglaniyor ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");

    Serial.println("WiFi baglandi");
    Serial.println("IP adres: ");
    Serial.println(WiFi.localIP());

    Serial.println("UDP Gonderme Basliyor");
    Udp.begin(localPort);
    Serial.print("Lokal port: ");
    Serial.println(Udp.localPort());

}

void loop() {
    OSCMessage msg1("/ydata");
    ldr=analogRead(A0); msg1.add(ldr);
    Udp.beginPacket(outIp, outPort);
    msg1.send(Udp); Udp.endPacket(); msg1.empty();

    OSCMessage msg2("/xdata"); msg2.add(xdata);
    Udp.beginPacket(outIp, outPort);
    msg2.send(Udp); Udp.endPacket(); msg2.empty();
    delay(50); xdata++;
    if (xdata>100) xdata=0;
}

