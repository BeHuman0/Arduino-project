//İLYAS ATALAY
//Şifreli kapı giriş sistemi.(lcd,buzzer,led,servo motor bağlantılı.)

#include <Keypad.h>                     //keypad,LCD ekran ve servo motoru kullanmak için gerekli kütüphaneler eklendi.
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const byte satir = 4;                   //satır ve sutun sayıları belirlendi.
const byte sutun = 4;
char sifre[5]={'9','8','7','6','#'};    // bir şifre belirlendi.
char giris[5];                          // şifre girişi için dizi oluşturuldu.
int i=0;
int kled = 2;                           //Ledler ve buzzer için pinler atandı.
int yled = 3;
int buzzer = 4;
char tus_takimi[satir][sutun] = {       //Tuş takımı oluşturuldu.
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte satir_pin[]={10,11,12,13};         // Satır ve sutun pinleri girildi.
byte sutun_pin[]={9,8,7,6};

Keypad tuslar = Keypad(makeKeymap(tus_takimi), satir_pin, sutun_pin, satir,sutun); // Keypad nesnesi ile keypadimizin tuşları oluşturuldu.
LiquidCrystal_I2C lcd(0x27 , 16, 2);                                               // LCD ekran boyutları belirtildi ve nesne oluşturuldu.
Servo servo;                                                                       // Servo motor kullanımı için nesne oluşturuldu.
  
void setup() {
  pinMode(kled, OUTPUT);               // Pin giriş çıkışları ve bağlantılar tanımlandı.
  pinMode(yled,OUTPUT);
  pinMode(buzzer, OUTPUT);
  servo.attach(5);
  lcd.begin();/* LCD ekran başlatıldı. */
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hosgeldiniz...");
  delay(2500);
  servo.write(0);                     // servonun konumu sıfırlandı.
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sifre Giriniz:");
}
void loop() {
  char tus=tuslar.getKey();          // getKey komutu ile tuşa basıldıkça tuşu çekicek.
  
  if(tus){
      giris[i++] = tus;              // tuşa her basılışında giriş dizimize değeri atandı.
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      lcd.setCursor(i,1);            // Girilen şifre ekranda gösterildi.
      lcd.print(tus);
    }
    
  if(i == 5){
       delay(50);
       if(strncmp(sifre, giris, 5) == 0){  //strncmp komutu ile stringlerin 4 elemanı karşılaştırıldı.
       lcd.clear();
       lcd.print("Sifre Dogru!");          // Girilen şifre ile oluşturulan şifre eşit ise şifre doğru.
       delay(250);
       digitalWrite(yled, HIGH);
       digitalWrite(kled,LOW);
       lcd.clear();
       lcd.println("Kapi aciliyor...");   
       servo.write(100);                   // Kapı açılıyor.
       digitalWrite(buzzer, HIGH);
       delay(100);
       digitalWrite(buzzer, LOW);
       delay(100);
       digitalWrite(buzzer, HIGH);
       delay(100);
       digitalWrite(buzzer, LOW);
       delay(100);
       digitalWrite(buzzer, HIGH);
       delay(100);
       digitalWrite(buzzer, LOW);
       delay(2000);
       servo.write(0);                     // İşlemden 1 saniye sonra kapı kapatıldı ve tekrar şifre girişi istendi.
       digitalWrite(yled,LOW);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Sifre Giriniz:");
       i=0; /* i sıfırlanarak tekrar şifre girişi sağlanıyor. */
    }
    else
    {
     delay(50);
     lcd.clear();                          // Girilen şifre yanlışken kırmızı led yakıldı ve hata alarmı ile tekrar giriş istendi.
     lcd.setCursor(0,0);
     lcd.print("Sifre Yanlis!");
     lcd.setCursor(0,1);
     lcd.print("Tekrar giriniz.");
     digitalWrite(yled, LOW);
     digitalWrite(kled,HIGH);
     digitalWrite(buzzer, HIGH);
     delay(1000);
     digitalWrite(buzzer, LOW);
     delay(1000);
     digitalWrite(kled,LOW);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Sifre Giriniz:");
     i=0; /* i sıfırlanarak tekrar şifre girişi sağlanıyor. */
    }
  }
}  
