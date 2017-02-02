upload:
	pio run -t upload

seroku:
	python -m serial.tools.miniterm /dev/ttyUSB0 115200
libkur:
	@echo "pio lib search PubClient"
	pio lib install 89
	@echo "pio lib search dht"
	@echo "pio lib search DHT22"
	pio lib install 115
	pio lib install 19
