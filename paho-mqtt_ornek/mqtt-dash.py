import paho.mqtt.client as mqtt

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("ab2017/mesaj")
#   client.subscribe("ab2017/hava")
    client.subscribe("ab2017/lamba")

def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))

client = mqtt.Client()
#client.username_pw_set("user", "pass")

client.on_connect = on_connect
client.on_message = on_message

client.connect("iot.eclipse.org", 1883, 60)
#client.connect("broker.mqttdashboard.com", 1883,60)

client.loop_forever()

