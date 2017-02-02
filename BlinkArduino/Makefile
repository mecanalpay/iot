all:
	@echo "ESP8266 için     : make nodemcu"
	@echo "Arduino Uno için : make arduino"
nodemcu:
	pio run -e nodemcu -t upload --upload-port /dev/ttyUSB0
arduino:
	pio run -e uno -t upload --upload-port /dev/ttyUSB1

