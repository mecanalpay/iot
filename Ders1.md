

Internet üzerindeki nesneler bir Broker (Aracı, Simsar sunucu) üzerinden haberleşirler. 
Yayıncılar (Publisher) ve Aboneler (Subscriber) ler bir topic ile mesaj gönderirler. 
Bir topic e üye olan aboneler o topic altında gelen mesajlari görebilirler.
Deneme amaçlı üç tane topic açtık: hava , mesaj ve lamba

Cihazdan cihaza ve cihazdan buluta haberleşmeler için kursta kullanmak üzere bir bir Mosquitto MQTT sunucu kurduk.
Sunucumuzun IP adresi: 54.89.221.74

Sunucuyla ilgili denemeler yapmak için aşağıdaki işlemleri yapınız.

1. Android cihazlar için <a href=https://play.google.com/store/apps/details?id=net.routix.mqttdash>https://play.google.com/store/apps/details?id=net.routix.mqttdash</a> adresinden MQTT Dashboard ugulamazını kurun.

2. + İşaretine dokunarak MQTT  sunucusu ekleyeceğiz. 
Sadece aşağıdaki alanları doldurun.

Name: IOT Kursu
Adress: 54.89.221.74
Port: 1883
User name: xxxxx  (Maille gönderildi.)
User password: xxxx (Maille gönderildi)

Sağ üzt köşedeki kaydetme ikonunu kaydedin. Uygulama ana ekrana dönecektir.

3. Ekrandaki IOT Kursunu seçerek MQTT sunucumuza bağlanın.

4. Sağ üst köşedeki (+) işaretini seçip ve çıkan menüden sırasıyla Text, Switch/Button ve Image ekleyeceğiz.
    Text seçtiğinizde
    Name: Mesaj 
    Topic (sub): mesaj
    alanlarını girip kaydedin.
    
    Switch/Button Seçtiğinizde
    Name: Lamba
    Topic (sub) : lamba
    alanlarını girip kaydedin.
    
    Image Seçtiğinizde
    (x) Image file data received as binary payload contents
    Name: Hava Durumu
    Topic (sub): hava
    alanlarını girip kaydedin. 
    
Mesaj üzerine dokunup Açılan set new Value ye bir mesaj yazın. Diğer abonelere ulaşacaktır.
Lamba anahtarına dokunduğunuzda açma kapama emri diğer abonelere de gönderilecektir.

Bir topic de siz oluşturup bize bildirebilirsiniz.

