import serial
with serial.Serial('/dev/ttyUSB0', 115200, timeout=10) as ser:
   x = ser.read()          
   s = ser.read(10)        
   line = ser.readline()   
