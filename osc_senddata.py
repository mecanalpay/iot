from pythonosc import osc_message_builder
from pythonosc import udp_client
import numpy as np
import time

client = udp_client.UDPClient('localhost', 9000)
for x in np.arange(0, 10, 0.1):
    msgx = osc_message_builder.OscMessageBuilder(address="/xdata")
    msgx.add_arg(x); msgx = msgx.build();  client.send(msgx)
    y=np.sin(x)
    msgy = osc_message_builder.OscMessageBuilder(address="/ydata")
    msgy.add_arg(y); msgy = msgy.build();  client.send(msgy)
    time.sleep(0.1)
