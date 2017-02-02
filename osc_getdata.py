import argparse
import math

from pythonosc import dispatcher
from pythonosc import osc_server

def xdata_handler(unused_addr,xdata):
  print("x=", xdata)

def ydata_handler(unused_addr,ydata):
  print("y=", ydata)

dispatcher = dispatcher.Dispatcher()
dispatcher.map("/xdata", xdata_handler)
dispatcher.map("/ydata", ydata_handler)
server = osc_server.ThreadingOSCUDPServer(
         ('localhost', 9000), dispatcher)
server.serve_forever()
