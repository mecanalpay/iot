import paho.mqtt.client as paho
import time,random
 
def on_publish(client, userdata, mid):
    print("mid: "+str(mid))
 
client = paho.Client()
#client.username_pw_set("ab2017", "abx")
client.on_publish = on_publish
#client.connect("broker.mqttdashboard.com", 1883)
client.connect("iot.eclipse.org",1883);

client.loop_start()
 
while True:
    sicaklik = random.randint(0,100)
    (rc, mid) = client.publish("ab2017/temp", str(sicaklik), qos=1)
    time.sleep(30)
