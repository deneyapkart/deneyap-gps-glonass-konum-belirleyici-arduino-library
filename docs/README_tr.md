# Deneyap GPS ve GLONASS Konum Belirleyici Arduino Kütüphanesi

Deneyap GPS ve GLONASS Konum Belirleyici için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M45**, **mpv1.0**
- `MCU` STM8S003F3, Quectel L86
- `Pil Yuvası` CR1220
- `Ağırlık`
- `Modul Boyutları` 25,4 mm x 38,1 mm
- `I2C Adres` 0x2F, 0x54, 0x73, 0x74

| Adres |  | 
| :--- | :---     |
| 0x2F | varsayılan adres |
| 0x54 | ADR1 kısa devre yapıldığındaki adres |
| 0x73 | ADR2 kısa devre yapıldığındaki adres |
| 0x74 | ADR1 ve ADR2 kısa devre yapıldığındaki adres |

## :closed_book:Dokümanlar
[Deneyap GPS ve GLONASS Konum Belirleyici](https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-gnss-m45)

[Deneyap GPS ve GLONASS Konum Belirleyici Şematik](https://cdn.deneyapkart.org/media/upload/userFormUpload/GEc26oFEFkPIzMT9PunlPEBJIslaoo2c.pdf)

[Deneyap GPS ve GLONASS Konum Belirleyici Teknik Resim](https://cdn.deneyapkart.org/media/upload/userFormUpload/Tyb470HrWmP4LJhrUGRGxiijpXCzBPN6.pdf)

[Quectel L86 - datasheet](https://www.quectel.com/wp-content/uploads/pdfupload/Quectel_L86_GNSS_Specification_V1.3.pdf)

[Arduino IDE'de Kütüphane Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap GPS ve GLONASS Konum Belirleyici
Bu Arduino kütüphanesi Deneyap GPS ve GLONASS Konum Belirleyiciyi I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.2 - kütüphaneye yeni fonksiyonlar eklendi

1.0.1 - hata giderildi

1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap GPS ve GLONASS Konum Belirleyici ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir. 

|GPS ve GLONASS Konum Belirleyici| Fonksiyon| Kart pinleri |
| :---       		| :---     	 |   :---     |
| 3.3V     			|3.3V Besleme Gerilimi| 3.3V    |
| GND      			| Toprak 		|GND      |
| SDA      			|Çift Yönlü Veri Hattı| SDA pini |
| SCL      			|Veri Hattı Zaman Senkronizasyon İşareti| SCL pini|
|SWIM 				| Debug	 	| bağlantı yok 	|
|RES  				| Debug 		| bağlantı yok 	|
|TX					|UART Arayüzü Veri Çıkışı| 				|
|RX					|UART Arayüzü Veri Girişi| 				|
|ADDET_N			||
|RES_N				||
|FORCE				||
|1PPS				||

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-gps-glonass-konum-belirleyici-arduino-library/blob/master/LICENSE) dosyasını inceleyin.
