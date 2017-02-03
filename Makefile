all:
	@echo "***** Komutlar *****"
	@echo "Kullanım: make komut"
	@echo "Komutlar: push sarj wifi wifiara uyu esp_info"
	@echo "nodemcu_integer .."
	

push:
	git status
	git add * */*
	git commit -m "Ekleme"
	git status
	git push 
sarj:
	@echo "=====> Labtop batarya durumu gösteriliyor "
	acpi -V

wifi:
	@echo "=====> BenimWiFi kablosuz ağına bağlanılıyor "
	nmcli dev wifi connect BenimWiFi password abc12345
wifiara:
	@echo "=====> WiFi Listesi"
	iwlist scanning| grep ESSID
uyu:
	@echo "=====> Kış uykusuna yatıyoruz "
	systemctl suspend

esp_info:
	sudo ./esptool.py --port /dev/ttyUSB0 flash_id

nodemcu_integer:
	@echo "ESP8266 Modülüne NodeMCU-Lua Integer Firmware i yazıyoruz" 
	sudo python ./esptool.py --port /dev/ttyUSB0 write_flash 0x00000 ./nodemcu_integer_0.9.6-dev_20150704.bin

nodemcu_float:
	@echo "ESP8266 Modülüne NodeMCU-Lua Float Firmware i yazıyoruz" 
	sudo python ./esptool.py --port /dev/ttyUSB0 write_flash 0x00000 ./nodemcu_float_0.9.6-dev_20150704.bin

	@echo "nodemcu-build.com adresinden olusturulan firmware"


weblua:
	sudo python ./luatool.py --port /dev/ttyUSB0 --src ./web.lua --dest init.lua --restart

initlua:
	sudo python ./luatool.py --port /dev/ttyUSB0 --src ./init.lua --dest init.lua --restart

espclean:
	sudo ./esptool.py --port /dev/ttyUSB0 erase_flash

at32:
	sudo ./esptool.py --port /dev/ttyUSB0 --baud 115200 write_flash 0x00000 AiThinker_ESP8266_DIO_32M_32M_20160615_V1.5.4.bin

at8:
	sudo ./esptool.py --port /dev/ttyUSB0 --baud 115200 write_flash 0x00000 AiThinker_ESP8266_DIO_8M_8M_20160615_V1.5.4.bin

