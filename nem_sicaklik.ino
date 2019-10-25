//İLYAS ATALAY 
//Nem Ve Sıcaklık ölçme projesi
#include <DHT.h> // Dht11 kütüphanesi eklendi.
#include <LiquidCrystal_I2C.h> // lcd ı2c kullanımı için kütüphane eklendi.
#include <Wire.h>

// gerekli nesneler ve değişkenler oluşturuldu.
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27 , 16, 2);

void setup() {
  lcd.begin(); /* lcd ekran başlatıldı*/
  lcd.print("Baslatiliyor");
  delay(500);
  dht.begin(); /*dht11 sensörü başlatıldı*/
}

void loop() {
  int sicaklik = dht.readTemperature(); //sensör ile ölçülen sıcaklık değeri değişkene kaydedildi.
  int nem = dht.readHumidity(); //sensör ile ölçülen nem değeri değişkene kaydedildi.

  lcd.clear(); /* döngü hızlı olması için ekran her döngüde temizlendi.*/
  lcd.setCursor(0, 0); /* sıcaklık değeri için satır ve sutunları belirlendi.*/
  lcd.print("Sicaklik: ");
  lcd.print(sicaklik); // sıcaklık değeri lcd ekrana yazdırıldı.
  lcd.print(" C");

  lcd.setCursor(0, 1); /* nem değeri için satır ve sutunları belirlendi.*/
  lcd.print("Nem: %"); 
  lcd.print(nem); // nem değeri lcd ekrana yazdırıldı
  
  delay(2000); /* 2 saniye bekleme ile döngü stabilleştirildi. */
}
