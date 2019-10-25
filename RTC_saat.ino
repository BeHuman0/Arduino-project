//İLYAS ATALAY
//RTC modül ile dijital saat uygulaması.

#include <virtuabotixRTC.h>                             //RTC ve LCD için gerekli kütüphaneler eklendi.
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int CLK_PIN = 2;
int DAT_PIN = 3;
int RST_PIN = 4;

virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);        //Rtc ve lcd ekran için nesneler oluşturuldu.
LiquidCrystal_I2C lcd(0x27 , 16, 2);

void setup() {
  lcd.begin();
  lcd.backlight();
  //myRTC.setDS1302Time(0,32,14,6,3,8,2019);            // Tarih ve saati ayarlamak için kullanılıyor.(saniye,dakika,saat,haftanın kaçıncı günü,ayın günü,ay,yıl)
  
}

void loop() {
  myRTC.updateTime();
  lcd.clear();                                          //Başlamadan önce ekranı temizliyoruz.
  lcd.setCursor(0,0);                                   //Ekranın ilk satır ilk sütunundan yazmaya başlıyoruz.
  lcd.print(myRTC.dayofmonth);                          //Gün ekrana yazdırıldı.
  lcd.print("/");
  lcd.print(myRTC.month);                               //Ay ekrana yazdırıldı.
  lcd.print("/");
  lcd.print(myRTC.year);                                //Yıl ekrana yazdırıldı.
  
  lcd.setCursor(0, 1);                                  //LCD'nin 2. satır 1. sütunundan yazmaya başlıyoruz.
  lcd.print(myRTC.hours);                               //Saat ekrana yazdırıldı.
  lcd.print(":");
  lcd.print(myRTC.minutes);                             //Dakika ekrana yazdırıldı.  
  lcd.print(":");
  lcd.print(myRTC.seconds);                             //Saniye ekrana yazdırıldı.
  delay(1000);    
}
