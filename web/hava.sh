rm hava.png
xvfb-run wkhtmltoimage  --height 200 --width 300 localhost/hava.html hava.png
mosquitto_pub -h localhost -t hava -f hava.png -u ab2017 -P abx
