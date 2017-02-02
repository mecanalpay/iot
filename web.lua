
wifi.setmode(wifi.STATION)
wifi.sta.config("WifiAdi","sifresi")
print(wifi.sta.getip())
led1 = 0
gpio.mode(led1, gpio.OUTPUT)
srv=net.createServer(net.TCP)
srv:listen(80,function(conn)
  conn:on("receive", function(client,request)
     local buf = "";
     local _, _, method, path, vars = 
       string.find(request,"([A-Z]+) (.+)?(.+) HTTP");
     if(method == nil)then
       _, _, method, path = 
       string.find(request, "([A-Z]+) (.+) HTTP");
     end
     local _GET = {}
     if (vars ~= nil)then
         for k, v in 
             string.gmatch(vars,"(%w+)=(%w+)&*") do
             _GET[k] = v
         end
     end
     buf = buf.."<h3> ESP8266 Web Sunucu</h3>";
     buf = buf.."<p>GPIO0 <a href=\"?pin=ON\">";
     buf = buf.."<button>KAPAT</button></a>&nbsp;";
     buf = buf.."<a href=\"?pin=OFF\"><button>";
     buf = buf.."A&Ccedil;</button></a></p>";
     local _on,_off = "",""
     if(_GET.pin == "ON")then
         gpio.write(led1, gpio.HIGH);
     elseif(_GET.pin == "OFF")then
         gpio.write(led1, gpio.LOW);
     end
     client:send(buf); client:close(); 
     collectgarbage();
    end)
end)

