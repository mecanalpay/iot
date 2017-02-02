
--init.lua
wifi.setmode(wifi.STATION)
wifi.sta.config("BizimWifi","abc123")
wifi.sta.connect()
tmr.alarm(1, 1000, 1, function()
if wifi.sta.getip()== nil then
 print("IP yok, Bekleniyor...")
else
  tmr.stop(1)
print("ESP8266 Modu :" .. wifi.getmode())
print("MAC adresi   :" .. wifi.ap.getmac())
print("IP Adresi    :" .. wifi.sta.getip())
dofile ("web.lua")
end
end)
