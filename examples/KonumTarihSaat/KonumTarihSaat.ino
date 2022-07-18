/*
 *   Konum Tarih ve Saat örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.s
 *   Deneyap GPS ve GLONASS Konum Belirleyici modülğ ile konum, tarih ve saat bilgisini
 *   seri terminale yazdırmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap GPS ve GLONASS Konum Belirleyici için oluşturulmuştur
 *      ------>  www.....com  <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-gps-glonass-konum-belirleyici-arduino-library  <------
 *
 */

#include <Deneyap_GPSveGLONASSkonumBelirleyici.h>     // Deneyap_GPSveGLONASSkonumBelirleyici kutuphanesi eklenmesi

GPS GPS;

void setup() {
    Serial.begin(115200);                             // Seri haberleşme başlatılması
    if (!GPS.begin(0x2F)) {                           // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");  // I2C bağlantısı başarısız olursa seri monitore yazdırılması
        while (1);
    }
}

void loop() {
    GPS.Read(RMC);                                     // Konum, tarih ve saat bilgisi seri terminale yazdırılması
    Serial.println("--------------------------------------------------");
    delay(100);
}
