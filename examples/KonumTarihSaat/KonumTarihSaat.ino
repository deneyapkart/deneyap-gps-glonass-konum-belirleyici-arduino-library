/*
 *   Konum Tarih ve Saat örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Deneyap GPS ve GLONASS Konum Belirleyici modülü ile konum, tarih ve saat bilgisini
 *   seri terminale yazdırmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap GPS ve GLONASS Konum Belirleyici için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-gnss-m45 <------
 *      ------>  https://github.com/deneyapkart/deneyap-gps-glonass-konum-belirleyici-arduino-library  <------
 *
 */

#include <Deneyap_GPSveGLONASSkonumBelirleyici.h>       // Deneyap GPS ve GLONASS Konum Belirleyici kutuphanesi eklenmesi

GPS GPS;                                                // GPS için class tanımlaması

void setup() {
    Serial.begin(115200);                               // Seri haberleşme başlatılması
    if (!GPS.begin(0x2F)) {                             // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");    // I2C bağlantısı başarısız olursa seri monitore yazdırılması
        while (1);
    }
}

void loop() {
    GPS.readGPS(RMC);                                   // NMEA protokolünün RMC mesaj türü ile verinin okunması

    Serial.print("Konum: ");                            // Konum verilerinin seri terimale yazdırılması
    float lat;
    lat = GPS.readLocationLat();
    Serial.printf("%.7f", lat);
    Serial.print(",");
    float lng;
    lng = GPS.readLocationLng();
    Serial.printf("%.7f\n", lng);
    
    Serial.print("Tarih: ");                            // Tarih verilerinin seri terimale yazdırılması
    int day;
    day = GPS.readDay();
    Serial.print(day);
    Serial.print("/");

    int month;
    month = GPS.readMonth();
    Serial.print(month);
    Serial.print("/");

    int year;
    year = GPS.readYear();
    Serial.println(year);

    Serial.print("Saat:  ");                            // Saat verilerinin seri terimale yazdırılması
    int hour;
    hour = GPS.readHour();
    Serial.print(hour);
    Serial.print(":");

    int minute;
    minute = GPS.readMinute();
    Serial.print(minute);
    Serial.print(":");

    int second;
    second = GPS.readSecond();
    Serial.println(second);
    Serial.println("");

    delay(1000);
}
