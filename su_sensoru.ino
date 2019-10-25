//İLYAS ATALAY
//Yağmur tespit ve alarm sistemi.

#include <LiquidCrystal_I2C.h>          //LCD ekran kullanımı için gerekli kütüphaneler eklendi.
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);     //LCD ekranı kullanabilmek için nesne oluşturuldu ve boyutu belirtildi.

int esikdegeri = 200;                   //Sensörden okunan değere göre bir eşit değeri atandı.
const int sensorPin = A0;               //Diğer işlemler için gerekli değişkenler oluşturuldu.
const int buzzerPin = 5;
const int ledPin = 6;
const int butonPin = 7;
int veri;

void setup() {                          //Pin giriş çıkışları atandı.
  pinMode(buzzerPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(butonPin,INPUT);
  lcd.begin();                          //LCD ekran başlatıldı.
  lcd.clear();
  lcd.print("Hosgeldiniz...");
  delay(1000);  
}

void loop() {                           
  veri = analogRead(sensorPin);         //Sensörden gelen değerler okundu ve değişkene atandı.
  if(digitalRead(butonPin) == HIGH){    //Anahtar kapalı iken ekrana sistemin durumu yazdırıldı.
    lcd.clear();
    digitalWrite(buzzerPin,LOW);
    digitalWrite(ledPin,LOW);
    lcd.setCursor(0,0);
    lcd.print("Alarm kapali.");
    for(int i=0;i<17;i++){/*"Anahtarı açın" ifadesi için kayan yazı ayarlandı.*/
    lcd.setCursor(i,1);
    lcd.print("Anahtari acin.");
    delay(500);
    lcd.setCursor(i,1);
    lcd.print(" ");
    }
  }
  else if(veri > esikdegeri)            //Anahtar açıkken gelen veri eşik değerinden büyük ise alarmı çalıştırıp durumu ekranda göstericek.
  { 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.println("Yagmur yagiyor! ");
    digitalWrite(buzzerPin,HIGH);
    digitalWrite(ledPin,HIGH);
    delay(200);
    digitalWrite(buzzerPin,LOW);
    digitalWrite(ledPin,LOW);
  }
  else if(veri <= esikdegeri)           //Eğer gelen veri eşik değerinden düşükse alarmı kapatıp durumu ekranda belirticek.
  { 
    digitalWrite(buzzerPin,LOW);
    digitalWrite(ledPin,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Yagmur yagmiyor.");
    delay(50);
  }
}
