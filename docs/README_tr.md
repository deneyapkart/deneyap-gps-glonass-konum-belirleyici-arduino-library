# Deneyap GPS ve GLONASS Konum Belirleyici Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap GPS ve GLONASS Konum Belirleyici için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M45**, **mpv1.0**
- `MCU` STM8S003F3, Quectel L86
- `Ağırlık`
- `Modul Boyutları` 
- `I2C Adres` 0x2F, 0x54, 0x73, 0x74

| Adres |  | 
| :--- | :---     |
| 0x2F | varsayılan adres |
| 0x54 | ADR1 kısa devre yapıldığındaki adres |
| 0x73 | ADR2 kısa devre yapıldığındaki adres |
| 0x74 | ADR1 ve ADR2 kısa devre yapıldığındaki adres |

## :closed_book:Dokümanlar
Deneyap GPS ve GLONASS Konum Belirleyici

[Quectel L86](https://cdn.ozdisan.com/ETicaret_Dosya/456042_3622410.pdf)

[Arduino Kütüphanesi Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap GPS ve GLONASS Konum Belirleyici
Bu Arduino kütüphanesi Deneyap GPS ve GLONASS Konum Belirleyiciyi I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap GPS ve GLONASS Konum Belirleyici ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir. 

|GPS ve GLONASS Konum Belirleyici| Fonksiyon| Kart pinleri |
| :---       		| :---     	 |   :---     |
| 3.3V     			| Güç    		| 3.3V    |
| GND      			| Toprak 		|GND      |
| SDA      			| I2C Data  	| SDA pini |
| SCL      			| I2C Clock 	| SCL pini|
|SWIM 				| Debug	 	| bağlantı yok 	|
|RES  				| Debug 		| bağlantı yok 	|
|TX					| Transmit pin 	| 				|
|RX					|  Receive pin 	| 				|
|ADDET_N			||
|RES_N				||
|FORCE				||
|1PPS				||

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-gps-glonass-konum-belirleyici-arduino-library/blob/master/LICENSE) dosyasını inceleyin.
